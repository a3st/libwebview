// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "platform/edge.hpp"
#include "precompiled.h"
#include <wrl/event.h>
using namespace Microsoft::WRL;
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#define THROW_IF_FAILED(HRESULT)                                                                                       \
    if (FAILED(HRESULT))                                                                                               \
    {                                                                                                                  \
        throw std::runtime_error(                                                                                      \
            std::format("An error occurred while processing the WINAPI (HRESULT: {:04x})", HRESULT));                  \
    }

namespace libwebview
{
    namespace internal
    {
        auto to_wstring(std::string_view const source) -> std::wstring
        {
            int32_t length =
                ::MultiByteToWideChar(CP_UTF8, 0, source.data(), static_cast<int32_t>(source.size()), nullptr, 0);

            std::wstring dest(length, '\0');

            ::MultiByteToWideChar(CP_UTF8, 0, source.data(), static_cast<int32_t>(source.size()), dest.data(), length);
            return dest;
        }

        auto to_string(std::wstring_view const source) -> std::string
        {
            int32_t length = WideCharToMultiByte(CP_UTF8, 0, source.data(), static_cast<int32_t>(source.size()),
                                                 nullptr, 0, nullptr, nullptr);

            std::string dest(length, '\0');

            WideCharToMultiByte(CP_UTF8, 0, source.data(), static_cast<int32_t>(source.size()), dest.data(),
                                static_cast<int32_t>(dest.size()), nullptr, nullptr);
            return dest;
        }
    } // namespace internal

    auto Edge::window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT
    {
        auto window = reinterpret_cast<Edge*>(::GetWindowLongPtr(hwnd, GWLP_USERDATA));

        if (!window)
        {
            return ::DefWindowProc(hwnd, msg, wparam, lparam);
        }

        switch (msg)
        {
            case WM_DESTROY: {
                ::PostQuitMessage(0);
                break;
            }
            case WM_SIZE: {
                if (!window->controller)
                {
                    return 0;
                }

                auto rect = RECT{};
                ::GetClientRect(window->window, &rect);
                window->controller->put_Bounds(rect);
                break;
            }
            case WM_GETMINMAXINFO: {
                MINMAXINFO* mmi = (MINMAXINFO*)lparam;
                mmi->ptMinTrackSize.x = window->min_window_width;
                mmi->ptMinTrackSize.y = window->min_window_height;

                if (std::make_tuple(window->max_window_width, window->max_window_height) != std::make_tuple(0u, 0u))
                {
                    mmi->ptMaxTrackSize.x = window->max_window_width;
                    mmi->ptMaxTrackSize.y = window->max_window_height;
                }
                return 0;
            }
        }
        return ::DefWindowProc(hwnd, msg, wparam, lparam);
    }

    auto Edge::navigation_completed(ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT
    {
        if (!is_initialized)
        {
            is_initialized = true;

            ::ShowWindow(window, SW_SHOWNORMAL);
            ::UpdateWindow(window);
            ::SetFocus(window);

            THROW_IF_FAILED(controller->put_IsVisible(TRUE));

            auto rect = RECT{};
            ::GetClientRect(window, &rect);
            THROW_IF_FAILED(controller->put_Bounds(rect));
        }
        return S_OK;
    }

    auto Edge::web_message_received(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT
    {
        LPWSTR buffer;
        THROW_IF_FAILED(args->TryGetWebMessageAsString(&buffer));

        auto message_data = json::parse(internal::to_string(buffer));
        auto index = message_data["index"].get<uint64_t>();
        auto func_name = message_data["func"].get<std::string>();
        auto args_data = message_data["args"].dump();

        auto found = callbacks.find(func_name);
        if (found != callbacks.end())
        {
            found->second.first(index, args_data);
        }

        ::CoTaskMemFree(buffer);
        return S_OK;
    }

    Edge::Edge(std::string_view const app_name, std::string_view const title, uint32_t const width,
               uint32_t const height, bool const resizeable, bool const debug_mode)
        : is_initialized(false), semaphore(0)
    {
        THROW_IF_FAILED(::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED));
        THROW_IF_FAILED(::SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE));

        auto wnd_class = WNDCLASSEX{.cbSize = sizeof(WNDCLASSEX),
                                    .lpfnWndProc = window_proc,
                                    .hInstance = ::GetModuleHandle(nullptr),
                                    .lpszClassName = "Above"};

        if (!::RegisterClassEx(&wnd_class))
        {
            throw std::runtime_error("Failed to register window class");
        }

        uint32_t style = WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

        if (resizeable)
        {
            style |= WS_THICKFRAME;
        }

        window = ::CreateWindowEx(WS_EX_DLGMODALFRAME, wnd_class.lpszClassName, std::string(title).c_str(), style,
                                  CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr,
                                  wnd_class.hInstance, nullptr);

        if (!window)
        {
            throw std::runtime_error("Failed to create window");
        }

        HMONITOR monitor = ::MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST);
        THROW_IF_FAILED(::GetScaleFactorForMonitor(monitor, &scale));

        ::SetWindowPos(window, nullptr, CW_USEDEFAULT, CW_USEDEFAULT, width * static_cast<float>(scale) / 100,
                       height * static_cast<float>(scale) / 100, SWP_NOMOVE);

        ::SetWindowLongPtr(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

        BOOL enabled = TRUE;
        THROW_IF_FAILED(::DwmSetWindowAttribute(window, DWMWA_USE_IMMERSIVE_DARK_MODE, &enabled, sizeof(enabled)));

        LPWSTR version;
        THROW_IF_FAILED(::GetAvailableCoreWebView2BrowserVersionString(nullptr, &version));

        if (!version)
        {
            throw std::runtime_error("WebView2 Runtime is not installed");
        }

        ::CoTaskMemFree(version);

        std::filesystem::path const app_data = std::getenv("APPDATA");

        auto options = Make<CoreWebView2EnvironmentOptions>();
        THROW_IF_FAILED(options->put_AdditionalBrowserArguments(L"--disable-web-security"));

        THROW_IF_FAILED(::CreateCoreWebView2EnvironmentWithOptions(
            nullptr, (app_data / app_name).wstring().c_str(), options.Get(),
            Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
                [&, this](HRESULT error_code, ICoreWebView2Environment* created_environment) -> HRESULT {
                    environment.attach(created_environment);
                    environment->AddRef();
                    semaphore.release();
                    return S_OK;
                })
                .Get()));

        auto msg = MSG{};

        while (!semaphore.try_acquire() && ::GetMessage(&msg, nullptr, 0, 0))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }

        THROW_IF_FAILED(environment->CreateCoreWebView2Controller(
            window, Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                        [&, this](HRESULT error_code, ICoreWebView2Controller* created_controller) -> HRESULT {
                            controller.attach(created_controller);
                            controller->AddRef();
                            semaphore.release();
                            return S_OK;
                        })
                        .Get()));

        while (!semaphore.try_acquire() && ::GetMessage(&msg, nullptr, 0, 0))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }

        THROW_IF_FAILED(controller->get_CoreWebView2(webview.put()));

        THROW_IF_FAILED(webview->add_NavigationCompleted(
            Callback<ICoreWebView2NavigationCompletedEventHandler>(this, &Edge::navigation_completed).Get(), &token));

        THROW_IF_FAILED(webview->add_WebMessageReceived(
            Callback<ICoreWebView2WebMessageReceivedEventHandler>(this, &Edge::web_message_received).Get(), &token));

        winrt::com_ptr<ICoreWebView2Settings> settings;
        THROW_IF_FAILED(webview->get_Settings(settings.put()));

        THROW_IF_FAILED(settings->put_AreDevToolsEnabled(debug_mode ? TRUE : FALSE));
        THROW_IF_FAILED(settings->put_AreDefaultContextMenusEnabled(debug_mode ? TRUE : FALSE));
    }

    auto Edge::set_max_size(uint32_t const width, uint32_t const height) -> void
    {
        if (std::make_tuple(width, height) == std::make_tuple<uint32_t, uint32_t>(0, 0))
        {
            uint32_t style = ::GetWindowLong(window, GWL_STYLE);
            if (!(style & WS_MAXIMIZEBOX))
            {
                style |= WS_MAXIMIZEBOX;
                ::SetWindowLong(window, GWL_STYLE, style);
            }
        }
        else
        {
            uint32_t style = ::GetWindowLong(window, GWL_STYLE);
            if (style & WS_MAXIMIZEBOX)
            {
                style &= ~WS_MAXIMIZEBOX;
                ::SetWindowLong(window, GWL_STYLE, style);
            }
        }

        max_window_width = width * static_cast<uint32_t>(scale) / 100;
        max_window_height = height * static_cast<uint32_t>(scale) / 100;
    }

    auto Edge::set_min_size(uint32_t const width, uint32_t const height) -> void
    {
        min_window_width = width * static_cast<uint32_t>(scale) / 100;
        min_window_height = height * static_cast<uint32_t>(scale) / 100;
    }

    auto Edge::set_size(uint32_t const width, uint32_t const height) -> void
    {
        ::SetWindowPos(window, nullptr, CW_USEDEFAULT, CW_USEDEFAULT, width * static_cast<uint32_t>(scale) / 100,
                       height * static_cast<uint32_t>(scale) / 100, SWP_NOMOVE);
    }

    auto Edge::run(std::string_view const url_path) -> void
    {
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
            static MAX_RESULTS = 100000;

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

        THROW_IF_FAILED(webview->AddScriptToExecuteOnDocumentCreated(js.c_str(), nullptr));

        if (url_path.starts_with("http://") || url_path.starts_with("https://"))
        {
            THROW_IF_FAILED(webview->Navigate(internal::to_wstring(url_path).c_str()));
        }
        else
        {
            auto current_path = std::filesystem::current_path();
            THROW_IF_FAILED(webview->Navigate(
                internal::to_wstring("file:///" + (current_path / url_path).generic_string()).c_str()));
        }

        auto msg = MSG{};
        bool running = true;

        while (running)
        {
            if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
            {
                switch (msg.message)
                {
                    case WM_QUIT: {
                        running = false;
                        break;
                    }
                    default: {
                        if (msg.hwnd)
                        {
                            ::TranslateMessage(&msg);
                            ::DispatchMessage(&msg);
                        }
                        break;
                    }
                }
            }
            else
            {
                while (!main_queue.empty())
                {
                    auto element = main_queue.pop_front();
                    element.first();
                    delete element.second;
                }

                if (idle.first)
                {
                    idle.first();
                }
            }
        }

        THROW_IF_FAILED(controller->Close());
    }

    auto Edge::execute_js(std::string_view const js) -> void
    {
        THROW_IF_FAILED(webview->ExecuteScript(internal::to_wstring(js).c_str(), nullptr));
    }

    auto Edge::quit() -> void
    {
        ::PostQuitMessage(0);
    }
} // namespace libwebview