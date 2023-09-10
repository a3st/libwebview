#include "precompiled.h"
#include "webview.h"
using namespace elbot::webview;
#include <wrl/event.h>
using namespace Microsoft::WRL;
#include <dwmapi.h>

using dispatch_func_t = std::function<HRESULT()>;

#define THROW_HRESULT_IF_FAILED(HRESULT) if(FAILED(HRESULT))\
{ throw std::runtime_error(std::format("An error occurred while processing the WINAPI (HRESULT: {:04x})", HRESULT)); } 

auto wstring_convert(std::string_view const source) -> std::wstring {
    int32_t length = MultiByteToWideChar(
        CP_UTF8, 
        0, 
        source.data(), 
        static_cast<int32_t>(source.size()),
        nullptr,
        0
    );

    std::wstring dest(length, '\0');

    MultiByteToWideChar(
        CP_UTF8, 
        0, 
        source.data(), 
        static_cast<int32_t>(source.size()),
        dest.data(),
        length
    );
    return dest;
}

auto string_convert(std::wstring_view const source) -> std::string {
    int32_t length = WideCharToMultiByte(
        CP_UTF8, 
        0, 
        source.data(), 
        static_cast<int32_t>(source.size()), 
        nullptr, 
        0, 
        nullptr, 
        nullptr
    );
    
    std::string dest(length, '\0');

    WideCharToMultiByte(
        CP_UTF8, 
        0, 
        source.data(), 
        static_cast<int32_t>(source.size()), 
        dest.data(), 
        static_cast<int32_t>(dest.size()), 
        nullptr, 
        nullptr
    );
    return dest;                                 
}

auto Webview::webview_window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT {
    auto window = reinterpret_cast<Webview*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    switch(msg) {
        case WM_DESTROY: {
            ::PostQuitMessage(0);
        } break;
        case WM_SIZE: {
            if(!window->controller) {
                return 0;
            }

            auto rect = RECT {};
            ::GetClientRect(window->window, &rect);
            window->controller->put_Bounds(rect);
        } break;
        default: {
            return ::DefWindowProcA(hwnd, msg, wparam, lparam);
        } break;
    }
    return 0;
}

auto Api::add_func(std::string_view const name, bind_func_t const& func) -> void {
    std::string func_name(name.data(), name.size());
    if(functions.find(func_name) != functions.end()) {
        throw std::runtime_error("The function already exists in API object");
    }

    functions.insert({ func_name, func });
}

Webview::Webview(
    std::string_view const title, 
    std::string_view const url, 
    uint32_t const width, 
    uint32_t const height, 
    std::filesystem::path const& user_data,
    std::string_view const app_name,
    Api& api,
    bool is_debug
) : is_initialized(false), main_thread_id(::GetCurrentThreadId()), thread_pool(1) {
    THROW_HRESULT_IF_FAILED(::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED));

    auto wnd_class = WNDCLASSA {
        .lpfnWndProc = webview_window_proc,
        .hInstance = ::GetModuleHandle(nullptr),
        .hIcon = static_cast<HICON>(::LoadImage(nullptr, "resources/win32/icon_150x150.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED)),
        .lpszClassName = "Webview2"
    };

    if(!::RegisterClassA(&wnd_class)) {
        throw std::runtime_error("Failed to register window class");
    }

    window = CreateWindowA(
        wnd_class.lpszClassName,
        title.data(),
        WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX),
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        width,
        height,
        nullptr,
        nullptr,
        wnd_class.hInstance,
        nullptr
    );

    if(!window) {
        throw std::runtime_error("Failed to create window");
    }

    SetWindowLongPtr(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

    BOOL enabled = TRUE;
    THROW_HRESULT_IF_FAILED(::DwmSetWindowAttribute(window, DWMWA_USE_IMMERSIVE_DARK_MODE, &enabled, sizeof(enabled)));

    LPWSTR version;
    THROW_HRESULT_IF_FAILED(::GetAvailableCoreWebView2BrowserVersionString(nullptr, &version));

    if(!version) {
        throw std::runtime_error("WebView2 Runtime is not installed");
    }
    ::CoTaskMemFree(version);

    std::wstring user_data_path = user_data.wstring() + wstring_convert(app_name);

    THROW_HRESULT_IF_FAILED(::CreateCoreWebView2EnvironmentWithOptions(
        nullptr, 
        user_data_path.c_str(),
        nullptr, 
        Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
            [&, this](HRESULT error_code, ICoreWebView2Environment* created_environment) -> HRESULT {
                if(FAILED(error_code)) {
                    return error_code;
                }
                environment.attach(created_environment);
                auto environment3 = environment.try_as<ICoreWebView2Environment3>();
                
                error_code = environment3->CreateCoreWebView2Controller(
                    window, 
                    Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                        [&, this](HRESULT error_code, ICoreWebView2Controller* created_controller) -> HRESULT {
                            controller.attach(created_controller);

                            error_code = controller->get_CoreWebView2(webview.put());
                            if(FAILED(error_code)) {
                                return error_code;
                            }

                            auto webview3 = webview.try_as<ICoreWebView2_3>();

                            error_code = webview3->add_NavigationCompleted(
                                Callback<ICoreWebView2NavigationCompletedEventHandler>(
                                    [&, this](ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT {
                                        if(!is_initialized) {
                                            is_initialized = true;

                                            ShowWindow(window, SW_SHOWNORMAL);
                                            UpdateWindow(window);
                                            SetFocus(window);

                                            controller->put_IsVisible(TRUE);

                                            auto rect = RECT {};
                                            ::GetClientRect(window, &rect);
                                            controller->put_Bounds(rect);
                                        }
                                        return S_OK;
                                    }
                                )
                                .Get(),
                                &token
                            );

                            if(FAILED(error_code)) {
                                return error_code;
                            }

                            error_code = webview3->add_WebMessageReceived(
                                Callback<ICoreWebView2WebMessageReceivedEventHandler>(
                                    [&, this](ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT {
                                        LPWSTR buffer;

                                        HRESULT error_code = args->TryGetWebMessageAsString(&buffer);
                                        if(FAILED(error_code)) {
                                            return error_code;
                                        }

                                        picojson::value data;

                                        std::string error_parse = picojson::parse(data, string_convert(std::wstring_view(buffer)));
                                        if(!error_parse.empty()) {
                                            throw std::runtime_error(error_parse);
                                        }

                                        int64_t index = data.get("index").get<int64_t>();
                                        std::string func_name = data.get("func").get<std::string>();
                                        picojson::value func_args = data.get("args");

                                        auto found = callbacks.find(func_name);
                                        if(found != callbacks.end()) {
                                            thread_pool.push_task(
                                                [&, found, index, func_args]() -> void {
                                                    PromiseResult result = found->second(*this, func_args);
                                            
                                                    std::string serialized_message = result.message.serialize();
                                                    if(result.type == PromiseResultType::Resolve) {
                                                        std::string js = "__callbacks[" + std::to_string(index) + "].resolve(" + serialized_message + "); delete __callbacks[" + 
                                                            std::to_string(index) + "];";
                                                        execute_js(js);
                                                    } else {
                                                        std::string js = "__callbacks[" + std::to_string(index) + "].reject(" + serialized_message + "); delete __callbacks[" + 
                                                            std::to_string(index) + "];";
                                                        execute_js(js);
                                                    }
                                                }
                                            );
                                        }

                                        ::CoTaskMemFree(buffer);
                                        return S_OK;
                                    }
                                )
                                .Get(),
                                &token
                            );

                            if(FAILED(error_code)) {
                                return error_code;
                            }

                            winrt::com_ptr<ICoreWebView2Settings> settings;
                            error_code = webview3->get_Settings(settings.put());
                            if(FAILED(error_code)) {
                                return error_code;
                            }

                            settings->put_AreDevToolsEnabled(is_debug ? TRUE : FALSE);
                            settings->put_AreDefaultContextMenusEnabled(is_debug ? TRUE : FALSE);

                            std::filesystem::path const res_dir = std::filesystem::current_path() / "resources";

                            error_code = webview3->SetVirtualHostNameToFolderMapping(
                                wstring_convert(app_name).c_str(), 
                                res_dir.wstring().c_str(), 
                                COREWEBVIEW2_HOST_RESOURCE_ACCESS_KIND_DENY
                            );
                            if(FAILED(error_code)) {
                                return error_code;
                            }

                            error_code = webview3->AddScriptToExecuteOnDocumentCreated(
                                L"let __callbacks = {}; let __callbacks_index = 0;", 
                                nullptr
                            );
                            if(FAILED(error_code)) {
                                return error_code;
                            }

                            for(auto const& [name, func] : api.functions) {
                                callbacks.insert({ name, func });
                                std::wstring js = L"let " + wstring_convert(std::string_view(name.data(), name.size())) +
                                LR"( = function() {
                                    let index = __callbacks_index++;

                                    let promise = new Promise(function(resolve, reject) {
                                        __callbacks[index] = {
                                            resolve: resolve,
                                            reject: reject
                                        };
                                    });

                                    window.chrome.webview.postMessage(
                                        JSON.stringify({
                                            index: index,
                                            func: arguments.callee.name,
                                            args: Array.from(arguments)
                                        })
                                    );
                                    return promise;
                                })";
                                error_code = webview3->AddScriptToExecuteOnDocumentCreated(js.c_str(), nullptr);
                                if(FAILED(error_code)) {
                                    return error_code;
                                }
                            }

                            error_code = webview3->Navigate(wstring_convert(url).c_str());
                            if(FAILED(error_code)) {
                                return error_code;
                            }

                            controller->AddRef();
                            return S_OK;
                        }
                    ).Get()
                );

                environment->AddRef();
                return S_OK;
            }
        ).Get()
    ));
}

auto Webview::run() -> void {
    auto msg = MSG {};
    bool running = true;

    while(running) {
        if(GetMessageA(&msg, nullptr, 0, 0) != -1) {
            switch(msg.message) {
                case WM_QUIT: {
                    running = false;
                } break;
                case WM_APP: {
                    auto func = reinterpret_cast<dispatch_func_t*>(msg.lParam);
                    THROW_HRESULT_IF_FAILED((*func)());
                    delete func;
                } break;
                default: {
                    if(msg.hwnd) {
                        ::TranslateMessage(&msg);
                        ::DispatchMessageA(&msg);
                    }
                } break;
            }
        }
    }
}

auto Webview::execute_js(std::string_view const js) -> void {
    if(::PostThreadMessageA(
            main_thread_id, 
            WM_APP, 
            WM_USER, 
            reinterpret_cast<LPARAM>(
                new dispatch_func_t([data = wstring_convert(js), this]() -> HRESULT {
                    return webview->ExecuteScript(data.c_str(), nullptr);
                })
            )
        ) == 0
    ) {
        throw std::runtime_error("An error occurred while sending a message to the thread");
    }
}

auto Webview::terminate() -> void {
    if(::PostThreadMessageA(
            main_thread_id, 
            WM_APP, 
            WM_USER, 
            reinterpret_cast<LPARAM>(
                new dispatch_func_t([]() -> HRESULT {
                    ::PostQuitMessage(0);
                    return S_OK;
                })
            )
        ) == 0
    ) {
        throw std::runtime_error("An error occurred while sending a message to the thread");
    }
}