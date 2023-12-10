#include "precompiled.h"
#include "platform/edge.h"
#include <wrl/event.h>
using namespace Microsoft::WRL;
#include <nlohmann/json.hpp>
using json = nlohmann::json;

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

auto Edge::window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT {
    auto window = reinterpret_cast<Edge*>(::GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if(!window) {
        return ::DefWindowProc(hwnd, msg, wparam, lparam);
    }
    
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
        case WM_GETMINMAXINFO: {
            MINMAXINFO* mmi = (MINMAXINFO*)lparam;
            mmi->ptMinTrackSize.x = std::get<0>(window->min_window_size);
            mmi->ptMinTrackSize.y = std::get<1>(window->min_window_size);

            if(window->max_window_size != std::make_tuple(0u, 0u)) {
                mmi->ptMaxTrackSize.x = std::get<0>(window->max_window_size);
                mmi->ptMaxTrackSize.y = std::get<1>(window->max_window_size);
            }
            return 0;
        } break;
        default: {
            return ::DefWindowProc(hwnd, msg, wparam, lparam);
        } break;
    }
    return 0;
}

auto Edge::navigation_completed(ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT {
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

auto Edge::web_message_received(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT {
    LPWSTR buffer;
    args->TryGetWebMessageAsString(&buffer);

    auto message_data = json::parse(internal::to_string(buffer));
    auto index = message_data["index"].get<uint64_t>();
    auto func_name = message_data["func"].get<std::string>();
    auto args_data = message_data["args"].dump();

    auto found = callbacks.find(func_name);
    if(found != callbacks.end()) {
        thread_queue.push_task(
            [&, found, index, args_data]() -> void {
                found->second(index, args_data);
            }
        );
    }
    
    ::CoTaskMemFree(buffer);
    return S_OK;
}

Edge::Edge(
    std::string_view const app_name,
    std::string_view const title, 
    std::tuple<uint32_t, uint32_t> const size, 
    bool const resizeable,
    bool const is_debug
) :
    is_initialized(false), semaphore(0),
    main_thread_id(::GetCurrentThreadId()),
    min_window_size(1, 1), max_window_size(0, 0)
{
    THROW_HRESULT_IF_FAILED(::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED));
    THROW_HRESULT_IF_FAILED(::SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE));

    auto wnd_class = WNDCLASSEX {
        .cbSize = sizeof(WNDCLASSEX),
        .lpfnWndProc = window_proc,
        .hInstance = ::GetModuleHandle(nullptr),
        .lpszClassName = "Above"
    };

    if(!::RegisterClassEx(&wnd_class)) {
        throw std::runtime_error("Failed to register window class");
    }

    uint32_t style = WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

    if(resizeable) {
        style |= WS_THICKFRAME;
    }

    window = ::CreateWindowEx(
        WS_EX_DLGMODALFRAME,
        wnd_class.lpszClassName,
        std::string(title).c_str(),
        style,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        nullptr,
        nullptr,
        wnd_class.hInstance,
        nullptr
    );

    if(!window) {
        throw std::runtime_error("Failed to create window");
    }

    HMONITOR monitor = ::MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST);
    THROW_HRESULT_IF_FAILED(::GetScaleFactorForMonitor(monitor, &scale));

    ::SetWindowPos(
        window, 
        nullptr, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        std::get<0>(size) * static_cast<float>(scale) / 100, 
        std::get<1>(size) * static_cast<float>(scale) / 100, 
        SWP_NOMOVE
    );

    ::SetWindowLongPtr(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

    BOOL enabled = TRUE;
    THROW_HRESULT_IF_FAILED(::DwmSetWindowAttribute(window, DWMWA_USE_IMMERSIVE_DARK_MODE, &enabled, sizeof(enabled)));

    LPWSTR version;
    THROW_HRESULT_IF_FAILED(::GetAvailableCoreWebView2BrowserVersionString(nullptr, &version));

    if(!version) {
        throw std::runtime_error("WebView2 Runtime is not installed");
    }

    ::CoTaskMemFree(version);

    std::filesystem::path const app_data = std::getenv("APPDATA");

    THROW_HRESULT_IF_FAILED(::CreateCoreWebView2EnvironmentWithOptions(
        nullptr, 
        (app_data / app_name).wstring().c_str(),
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
        Callback<ICoreWebView2NavigationCompletedEventHandler>(this, &Edge::navigation_completed).Get(), 
        &token
    );

    webview->add_WebMessageReceived(
        Callback<ICoreWebView2WebMessageReceivedEventHandler>(this, &Edge::web_message_received).Get(), 
        &token
    );

    winrt::com_ptr<ICoreWebView2Settings> settings;
    THROW_HRESULT_IF_FAILED(webview->get_Settings(settings.put()));

    settings->put_AreDevToolsEnabled(is_debug ? TRUE : FALSE);
    settings->put_AreDefaultContextMenusEnabled(is_debug ? TRUE : FALSE);
}

auto Edge::set_max_size(std::tuple<uint32_t, uint32_t> const size) -> void {
    if(size == std::make_tuple<uint32_t, uint32_t>(0, 0)) {
        uint32_t style = ::GetWindowLong(window, GWL_STYLE);
        if(!(style & WS_MAXIMIZEBOX)) {
            style |= WS_MAXIMIZEBOX;
            ::SetWindowLong(window, GWL_STYLE, style);
        }
    } else {
        uint32_t style = ::GetWindowLong(window, GWL_STYLE);
        if(style & WS_MAXIMIZEBOX) {
            style &= ~WS_MAXIMIZEBOX;
            ::SetWindowLong(window, GWL_STYLE, style);
        }
    }

    auto dpi_size = std::make_tuple<uint32_t, uint32_t>(
        std::get<0>(size) * static_cast<uint32_t>(scale) / 100, 
        std::get<1>(size) * static_cast<uint32_t>(scale) / 100
    );
    max_window_size = dpi_size;
}

auto Edge::set_min_size(std::tuple<uint32_t, uint32_t> const size) -> void {
    auto dpi_size = std::make_tuple<uint32_t, uint32_t>(
        std::get<0>(size) * static_cast<uint32_t>(scale) / 100, 
        std::get<1>(size) * static_cast<uint32_t>(scale) / 100
    );
    min_window_size = dpi_size;
}

auto Edge::set_size(std::tuple<uint32_t, uint32_t> const size) -> void {
    ::SetWindowPos(
        window, 
        nullptr, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        std::get<0>(size) * static_cast<uint32_t>(scale) / 100, 
        std::get<1>(size) * static_cast<uint32_t>(scale) / 100, 
        SWP_NOMOVE
    );
}

auto Edge::run(std::string_view const file_path) -> void {
    std::wstring js = LR"(
        class Queue {
            constructor() {
                this.elements = {};
                this.head = 0;
                this.tail = 0;
            }

            enqueue(element) {
                this.elements[this.tail] = element;
                this.tail++;
            }

            dequeue() {
                const item = this.elements[this.head];
                delete this.elements[this.head];
                this.head++;
                return item;
            }

            peek() {
                return this.elements[this.head];
            }

            length() {
                return this.tail - this.head;
            }

            isEmpty() {
                return this.length == 0;
            }
        }

        class IndexAllocator {
            constructor(count) {
                this.queue = new Queue();

                for(let i = 0; i < count; i++) {
                    this.queue.enqueue(i);
                }
            }

            allocate() {
                return this.queue.dequeue();
            }

            deallocate(element) {
                this.queue.enqueue(element);
            }
        }

        class WebView {
            static MAX_RESULTS = 100;

            constructor() {
                this.results = {};
                this.events = {};
                this.allocator = new IndexAllocator(WebView.MAX_RESULTS);
            }

            __free_result(index) {
                this.allocator.deallocate(index);
            }

            event(event, func) {
                this.events[event] = func;
            }

            invoke(name, ...args) {
                const index = this.allocator.allocate();

                let promise = new Promise((resolve, reject) => {
                        this.results[index] = {
                        resolve: resolve,
                        reject: reject
                    };
                });

                window.chrome.webview.postMessage(
                    JSON.stringify({
                        index: index,
                        func: name,
                        args: Array.from(args)
                    })
                );
                return promise;
            }
        }

        let webview = new WebView();
    )";

    THROW_HRESULT_IF_FAILED(webview->AddScriptToExecuteOnDocumentCreated(js.c_str(), nullptr));
    THROW_HRESULT_IF_FAILED(webview->Navigate(internal::to_wstring(file_path).c_str()));

    auto msg = MSG {};
    bool running = true;

    while(running) {
        if(::GetMessage(&msg, nullptr, 0, 0) != -1) {
            switch(msg.message) {
                case WM_QUIT: {
                    running = false;
                } break;
                /*case WM_APP: {
                    auto func = reinterpret_cast<dispatch_func_t*>(msg.lParam);
                    THROW_HRESULT_IF_FAILED((*func)());
                    delete func;
                } break;*/
                default: {
                    if(msg.hwnd) {
                        ::TranslateMessage(&msg);
                        ::DispatchMessage(&msg);
                    }
                } break;
            }
        }

        while(!main_queue.empty()) {
            THROW_HRESULT_IF_FAILED(main_queue.pop_front()());
        }
    }

    THROW_HRESULT_IF_FAILED(controller->Close());
}

auto Edge::bind(std::string_view const func_name, bind_func_t&& callback) -> void {
    if(callbacks.find(std::string(func_name)) != callbacks.end()) {
        throw std::runtime_error("Cannot to bind a function that already exists");
    }
    callbacks.insert({ std::string(func_name), std::move(callback) });
}

auto Edge::execute_js(std::string_view const js) -> void {
    main_queue.push(
        [data = internal::to_wstring(js), this]() -> HRESULT {
            return webview->ExecuteScript(data.c_str(), nullptr);
        }
    );
    /*if(::PostThreadMessage(
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
    }*/
}

auto Edge::result(uint64_t const index, bool const success, std::string_view const data) -> void {
    std::string js;
    if(success) {
        js = std::format("webview.results[{0}].resolve({1}); webview.__free_result({0});", index, data);
    } else {
        js = std::format("webview.results[{0}].reject({1}); webview.__free_result({0});", index, data);
    }
    execute_js(js);
}

auto Edge::quit() -> void {
    main_queue.push(
        []() -> HRESULT {
            ::PostQuitMessage(0);
            return S_OK;
        }
    );
    /*if(::PostThreadMessage(
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
    }*/
}

auto Edge::emit(std::string_view const event, std::string_view const data) -> void {
    std::string const js =
        R"(
            if(')" + std::string(event) + R"(' in webview.events) {
                webview.events[')" + std::string(event) + R"(']()" + std::string(data) + R"()
            }
        )";
    execute_js(js);
}