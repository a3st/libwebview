#include "precompiled.h"
#include "platform/webui_edge.h"
#include <wrl/event.h>
using namespace Microsoft::WRL;
#include <nlohmann/json.hpp>
using json = nlohmann::json;

using dispatch_func_t = std::function<HRESULT()>;

#define THROW_HRESULT_IF_FAILED(HRESULT) if(FAILED(HRESULT))\
{ throw std::runtime_error(std::format("An error occurred while processing the WINAPI (HRESULT: {:04x})", HRESULT)); }

namespace internal {

auto to_wstring(std::string_view const source) -> std::wstring {
    int32_t length = ::MultiByteToWideChar(
        CP_UTF8, 
        0, 
        source.data(), 
        static_cast<int32_t>(source.size()),
        nullptr,
        0
    );

    std::wstring dest(length, '\0');

    ::MultiByteToWideChar(
        CP_UTF8, 
        0, 
        source.data(), 
        static_cast<int32_t>(source.size()),
        dest.data(),
        length
    );
    return dest;
}

auto to_string(std::wstring_view const source) -> std::string {
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

}

auto WebUIEdge::window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT {
    auto window = reinterpret_cast<WebUIEdge*>(::GetWindowLongPtr(hwnd, GWLP_USERDATA));
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
        case WM_WINDOWPOSCHANGING: {
            auto window_pos = reinterpret_cast<LPWINDOWPOS>(lparam);
            
            if(window->min_window_size == std::make_tuple<uint32_t, uint32_t>(-1, -1) && 
                window->max_window_size != std::make_tuple<uint32_t, uint32_t>(-1, -1)) {
                window_pos->cx = std::clamp(
                    static_cast<uint32_t>(window_pos->cx), 
                    1u, 
                    std::get<0>(window->max_window_size)
                );
                window_pos->cy = std::clamp(
                    static_cast<uint32_t>(window_pos->cy), 
                    1u, 
                    std::get<1>(window->max_window_size)
                );
            } else if(window->min_window_size != std::make_tuple<uint32_t, uint32_t>(-1, -1) && 
                window->max_window_size == std::make_tuple<uint32_t, uint32_t>(-1, -1)) {
                window_pos->cx = std::clamp(
                    static_cast<uint32_t>(window_pos->cx), 
                    std::get<0>(window->min_window_size), 
                    std::numeric_limits<uint32_t>::max()
                );
                window_pos->cy = std::clamp(
                    static_cast<uint32_t>(window_pos->cy), 
                    std::get<1>(window->min_window_size), 
                    std::numeric_limits<uint32_t>::max()
                );
            } else {
                window_pos->cx = std::clamp(
                    static_cast<uint32_t>(window_pos->cx), 
                    std::get<0>(window->min_window_size), 
                    std::get<0>(window->max_window_size)
                );
                window_pos->cy = std::clamp(
                    static_cast<uint32_t>(window_pos->cy), 
                    std::get<1>(window->min_window_size), 
                    std::get<1>(window->max_window_size)
                );
            }
        } break;
        default: {
            return ::DefWindowProc(hwnd, msg, wparam, lparam);
        } break;
    }
    return 0;
}


auto WebUIEdge::navigation_completed(ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT {
    if(!is_initialized) {
        is_initialized = true;

        ::ShowWindow(window, SW_SHOWNORMAL);
        ::UpdateWindow(window);
        ::SetFocus(window);

        controller->put_IsVisible(TRUE);

        auto rect = RECT {};
        ::GetClientRect(window, &rect);
        controller->put_Bounds(rect);
    }
    return S_OK;
}


auto WebUIEdge::web_message_received(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT {
    LPWSTR buffer;
    args->TryGetWebMessageAsString(&buffer);

    auto message_data = json::parse(internal::to_string(buffer));
    auto index = message_data["index"].get<uint64_t>();
    auto func_name = message_data["func"].get<std::string>();
    auto args_data = message_data["args"].dump();

    auto found = js_callbacks.find(func_name);

    if(found != js_callbacks.end()) {
        thread_queue.push_task(
            [&, found, index, args_data]() -> void {
                found->second(index, args_data);
            }
        );
    }
    
    ::CoTaskMemFree(buffer);
    return S_OK;
}


WebUIEdge::WebUIEdge(
    std::string_view const title, 
    std::tuple<uint32_t, uint32_t> const size, 
    bool const resizeable,
    std::tuple<uint32_t, uint32_t> const min_size,
    std::tuple<uint32_t, uint32_t> const max_size, 
    bool const is_debug
) :
    is_initialized(false), semaphore(0), 
    main_thread_id(::GetCurrentThreadId()),
    min_window_size(min_size), max_window_size(max_size) 
{
    THROW_HRESULT_IF_FAILED(::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED));

    auto wnd_class = WNDCLASSEX {
        .cbSize = sizeof(WNDCLASSEX),
        .lpfnWndProc = window_proc,
        .hInstance = ::GetModuleHandle(nullptr),
        .lpszClassName = "WebUI"
    };

    if(!::RegisterClassEx(&wnd_class)) {
        throw std::runtime_error("Failed to register window class");
    }

    uint32_t style = WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX; 

    if(resizeable) {
        style |= WS_THICKFRAME;
    }

    if(max_size == std::make_tuple<uint32_t, uint32_t>(-1, -1)) {
        style |= WS_MAXIMIZEBOX;
    }

    window = ::CreateWindowEx(
        WS_EX_DLGMODALFRAME,
        wnd_class.lpszClassName,
        std::string(title).c_str(),
        style,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        std::get<0>(size),
        std::get<1>(size),
        nullptr,
        nullptr,
        wnd_class.hInstance,
        nullptr
    );

    if(!window) {
        throw std::runtime_error("Failed to create window");
    }

    ::SetWindowLongPtr(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

    BOOL enabled = TRUE;
    THROW_HRESULT_IF_FAILED(::DwmSetWindowAttribute(window, DWMWA_USE_IMMERSIVE_DARK_MODE, &enabled, sizeof(enabled)));

    LPWSTR version;
    THROW_HRESULT_IF_FAILED(::GetAvailableCoreWebView2BrowserVersionString(nullptr, &version));

    if(!version) {
        throw std::runtime_error("WebView2 Runtime is not installed");
    }

    ::CoTaskMemFree(version);

    // std::wstring user_data_path = user_data.wstring() + wstring_convert(app_name);

    THROW_HRESULT_IF_FAILED(::CreateCoreWebView2EnvironmentWithOptions(
        nullptr, 
        L"C:/Users/dima7/AppData/Roaming/test_app",
        nullptr, 
        Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
            [&, this](HRESULT error_code, ICoreWebView2Environment* created_environment) -> HRESULT {
                environment.attach(created_environment);
                environment->AddRef();
                semaphore.release();
                return S_OK;
            }
        ).Get()
    ));

    auto msg = MSG {};

    while(!semaphore.try_acquire() && ::GetMessage(&msg, nullptr, 0, 0)) {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }

    THROW_HRESULT_IF_FAILED(environment->CreateCoreWebView2Controller(
        window, 
        Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
            [&, this](HRESULT error_code, ICoreWebView2Controller* created_controller) -> HRESULT {
                controller.attach(created_controller);
                controller->AddRef();
                semaphore.release();
                return S_OK;
            }
        ).Get()
    ));

    while(!semaphore.try_acquire() && ::GetMessage(&msg, nullptr, 0, 0)) {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }

    THROW_HRESULT_IF_FAILED(controller->get_CoreWebView2(webview.put()));

    webview->add_NavigationCompleted(
        Callback<ICoreWebView2NavigationCompletedEventHandler>(this, &WebUIEdge::navigation_completed).Get(), 
        &token
    );

    webview->add_WebMessageReceived(
        Callback<ICoreWebView2WebMessageReceivedEventHandler>(this, &WebUIEdge::web_message_received).Get(), 
        &token
    );

    winrt::com_ptr<ICoreWebView2Settings> settings;
    THROW_HRESULT_IF_FAILED(webview->get_Settings(settings.put()));

    settings->put_AreDevToolsEnabled(is_debug ? TRUE : FALSE);
    settings->put_AreDefaultContextMenusEnabled(is_debug ? TRUE : FALSE);
}


auto WebUIEdge::run(std::string_view const index_file) -> void {
    std::wstring js = LR"(
        class WebUI {
            constructor() {
                this.callbacks = {};
                this.index = 0;
            }
    )";
    for(auto const& [name, func] : js_callbacks) {
        js += internal::to_wstring(name) +
            LR"((...args) {
                const index = this.index;
                let promise = new Promise((resolve, reject) => {
                        this.callbacks[index] = {
                        resolve: resolve,
                        reject: reject
                    };
                });
                window.chrome.webview.postMessage(
                    JSON.stringify({
                        index: index,
                        func: ')" + internal::to_wstring(name) + LR"(',
                        args: Array.from(args)
                    })
                );
                this.index ++;
                return promise;
            })";
    }
    js += LR"( 
        }
        let webUI = new WebUI();    
    )";

    webview->AddScriptToExecuteOnDocumentCreated(js.c_str(), nullptr);
    webview->Navigate(internal::to_wstring(index_file).c_str());

    auto msg = MSG {};
    bool running = true;

    while(running) {
        if(::GetMessage(&msg, nullptr, 0, 0) != -1) {
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
                        ::DispatchMessage(&msg);
                    }
                } break;
            }
        }
    }

    THROW_HRESULT_IF_FAILED(controller->Close());
}


auto WebUIEdge::bind(std::string_view const func_name, bind_func_t&& callback) -> void {
    if(js_callbacks.find(std::string(func_name)) != js_callbacks.end()) {
        throw std::runtime_error("Cannot to bind a function that already exists");
    }
    js_callbacks.insert({ std::string(func_name), std::move(callback) });
}


auto WebUIEdge::execute_js(std::string_view const js) -> void {
    if(::PostThreadMessage(
            main_thread_id, 
            WM_APP, 
            WM_USER, 
            reinterpret_cast<LPARAM>(
                new dispatch_func_t([data = internal::to_wstring(js), this]() -> HRESULT {
                    return webview->ExecuteScript(data.c_str(), nullptr);
                })
            )
        ) == 0
    ) {
        throw std::runtime_error("An error occurred while sending a message to the thread");
    }
}


auto WebUIEdge::result(uint64_t const index, bool const success, std::string_view const data) -> void {
    if(success) {
        std::string js = "webUI.callbacks[" + std::to_string(index) + "].resolve(" + std::string(data) + "); delete webUI.callbacks[" + 
            std::to_string(index) + "];";
        execute_js(js);
    } else {
        std::string js = "webUI.callbacks[" + std::to_string(index) + "].reject(" + std::string(data) + "); delete webUI.callbacks[" + 
            std::to_string(index) + "];";
        execute_js(js);
    }
}


auto WebUIEdge::quit() -> void {
    if(::PostThreadMessage(
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