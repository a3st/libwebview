#include "precompiled.h"
#include "platform/webui_edge.h"
#include <wrl/event.h>
using namespace Microsoft::WRL;

#define THROW_HRESULT_IF_FAILED(HRESULT) if(FAILED(HRESULT))\
{ throw std::runtime_error(std::format("An error occurred while processing the WINAPI (HRESULT: {:04x})", HRESULT)); }

auto wstring_convert(std::string_view const source) -> std::wstring {
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

auto WebUIEdge::window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT {
    auto window = reinterpret_cast<WebUIEdge*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
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
    return S_OK;
}

WebUIEdge::WebUIEdge(std::string_view const title, uint32_t const width, uint32_t const height) :
    is_initialized(false), semaphore(0) {
    THROW_HRESULT_IF_FAILED(::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED));

    auto wnd_class = WNDCLASS {
        .lpfnWndProc = window_proc,
        .hInstance = ::GetModuleHandle(nullptr),
        //.hIcon = static_cast<HICON>(::LoadImage(nullptr, "resources/win32/icon_150x150.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_DEFAULTSIZE | LR_SHARED)),
        .lpszClassName = "WebUI"
    };

    if(!::RegisterClass(&wnd_class)) {
        throw std::runtime_error("Failed to register window class");
    }

    window = ::CreateWindow(
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

    settings->put_AreDevToolsEnabled(TRUE);
    settings->put_AreDefaultContextMenusEnabled(TRUE);

    webview->AddScriptToExecuteOnDocumentCreated(
        L"let __callbacks = {}; let __callbacks_index = 0;", 
        nullptr
    );
}

auto WebUIEdge::run(std::string_view const index_file) -> void {
    std::cout << index_file << std::endl;
    webview->Navigate(wstring_convert(index_file).c_str());

    auto msg = MSG {};
    bool running = true;

    while(running) {
        if(GetMessageA(&msg, nullptr, 0, 0) != -1) {
            switch(msg.message) {
                case WM_QUIT: {
                    running = false;
                } break;
                case WM_APP: {
                    // auto func = reinterpret_cast<dispatch_func_t*>(msg.lParam);
                    // THROW_HRESULT_IF_FAILED((*func)());
                    // delete func;
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