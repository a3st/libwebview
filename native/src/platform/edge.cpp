// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "platform/edge.hpp"
#include "precompiled.h"
#include <wrl/event.h>
using namespace Microsoft::WRL;
#include "injection.hpp"
#include <commctrl.h>
#include <shobjidl.h>
#include <simdjson.h>

#if defined _M_IX86
#pragma comment(                                                                                                       \
    linker,                                                                                                            \
    "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(                                                                                                       \
    linker,                                                                                                            \
    "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(                                                                                                       \
    linker,                                                                                                            \
    "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(                                                                                                       \
    linker,                                                                                                            \
    "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

namespace libwebview
{
    auto throwIfFailed(HRESULT const hr) -> void
    {
        if (FAILED(hr))
        {
            throw std::runtime_error(std::format("The program closed with an error {:04x}", hr));
        }
    }

    namespace internal
    {
        auto toWString(std::string_view const source) -> std::wstring
        {
            int32_t length =
                ::MultiByteToWideChar(CP_UTF8, 0, source.data(), static_cast<int32_t>(source.size()), nullptr, 0);
            std::wstring dest(length, '\0');
            ::MultiByteToWideChar(CP_UTF8, 0, source.data(), static_cast<int32_t>(source.size()), dest.data(), length);
            return dest;
        }

        auto toString(std::wstring_view const source) -> std::string
        {
            int32_t length = ::WideCharToMultiByte(CP_UTF8, 0, source.data(), static_cast<int32_t>(source.size()),
                                                   nullptr, 0, nullptr, nullptr);
            std::string dest(length, '\0');
            ::WideCharToMultiByte(CP_UTF8, 0, source.data(), static_cast<int32_t>(source.size()), dest.data(),
                                  static_cast<int32_t>(dest.size()), nullptr, nullptr);
            return dest;
        }

        auto split(std::string const& source, std::string const& delimiter) -> std::vector<std::string>
        {
            size_t start = 0, end, delimeterLength = delimiter.length();
            std::string token;
            std::vector<std::string> result;

            while ((end = source.find(delimiter, start)) != std::string::npos)
            {
                token = source.substr(start, end - start);
                start = end + delimeterLength;
                result.emplace_back(token);
            }

            result.emplace_back(source.substr(start));
            return result;
        }
    } // namespace internal

    auto Edge::windowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT
    {
        auto windowInstance = reinterpret_cast<Edge*>(::GetWindowLongPtr(hWnd, GWLP_USERDATA));
        if (!windowInstance)
        {
            return ::DefWindowProc(hWnd, msg, wParam, lParam);
        }

        switch (msg)
        {
            case WM_DESTROY: {
                ::PostQuitMessage(0);
                break;
            }
            case WM_SIZE: {
                if (!windowInstance->controller)
                {
                    return 0;
                }

                RECT rect;
                ::GetClientRect(windowInstance->window, &rect);
                windowInstance->controller->put_Bounds(rect);
                break;
            }
            case WM_GETMINMAXINFO: {
                MINMAXINFO* mmi = (MINMAXINFO*)lParam;
                mmi->ptMinTrackSize.x = windowInstance->minSize.width;
                mmi->ptMinTrackSize.y = windowInstance->minSize.height;

                if (std::make_tuple(windowInstance->maxSize.width, windowInstance->maxSize.height) !=
                    std::make_tuple(0u, 0u))
                {
                    mmi->ptMaxTrackSize.x = windowInstance->maxSize.width;
                    mmi->ptMaxTrackSize.y = windowInstance->maxSize.height;
                }
                return 0;
            }
        }
        return ::DefWindowProc(hWnd, msg, wParam, lParam);
    }

    Edge::Edge(std::string_view const appName, std::string_view const title, uint32_t const width,
               uint32_t const height, bool const resizeable, bool const debugMode)
        : minSize{}, maxSize{}, isInitialized(false), semaphore(0)
    {
        throwIfFailed(::CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED));
        throwIfFailed(::SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE));

        WNDCLASSEX wndClass{.cbSize = sizeof(WNDCLASSEX),
                            .lpfnWndProc = windowProcedure,
                            .hInstance = ::GetModuleHandle(nullptr),
                            .lpszClassName = "LIB_WEBVIEW_APP"};

        if (!::RegisterClassEx(&wndClass))
        {
            throw std::runtime_error("Failed to register window class");
        }

        uint32_t style = WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;

        if (resizeable)
        {
            style |= WS_THICKFRAME;
        }

        window = ::CreateWindowEx(WS_EX_DLGMODALFRAME, wndClass.lpszClassName, std::string(title).c_str(), style,
                                  CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, nullptr, nullptr,
                                  wndClass.hInstance, nullptr);

        if (!window)
        {
            throw std::runtime_error("Failed to create window");
        }

        HMONITOR monitor = ::MonitorFromWindow(window, MONITOR_DEFAULTTONEAREST);
        throwIfFailed(::GetScaleFactorForMonitor(monitor, &scaleFactor));

        ::SetWindowPos(window, nullptr, CW_USEDEFAULT, CW_USEDEFAULT, width * static_cast<uint32_t>(scaleFactor) / 100,
                       height * static_cast<uint32_t>(scaleFactor) / 100, SWP_NOMOVE);

        ::SetWindowLongPtr(window, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

        BOOL enabled = TRUE;
        throwIfFailed(::DwmSetWindowAttribute(window, DWMWA_USE_IMMERSIVE_DARK_MODE, &enabled, sizeof(enabled)));

        LPWSTR version;
        throwIfFailed(::GetAvailableCoreWebView2BrowserVersionString(nullptr, &version));

        if (!version)
        {
            throw std::runtime_error("WebView2 runtime is not installed");
        }

        ::CoTaskMemFree(version);

        std::filesystem::path const appDataPath = std::getenv("APPDATA");

        auto options = Make<CoreWebView2EnvironmentOptions>();
        throwIfFailed(options->put_AdditionalBrowserArguments(L"--disable-web-security"));

        throwIfFailed(::CreateCoreWebView2EnvironmentWithOptions(
            nullptr, (appDataPath / appName).wstring().c_str(), options.Get(),
            Callback<ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler>(
                [&, this](HRESULT errorCode, ICoreWebView2Environment* createdEnvironment) -> HRESULT {
                    environment.attach(createdEnvironment);
                    environment->AddRef();
                    semaphore.release();
                    return S_OK;
                })
                .Get()));

        MSG msg;

        while (!semaphore.try_acquire() && ::GetMessage(&msg, nullptr, 0, 0))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }

        throwIfFailed(environment->CreateCoreWebView2Controller(
            window, Callback<ICoreWebView2CreateCoreWebView2ControllerCompletedHandler>(
                        [&, this](HRESULT errorCode, ICoreWebView2Controller* createdController) -> HRESULT {
                            controller.attach(createdController);
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

        throwIfFailed(controller->get_CoreWebView2(webview.put()));

        throwIfFailed(webview->add_NavigationCompleted(
            Callback<ICoreWebView2NavigationCompletedEventHandler>(
                [this](ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT {
                    if (!isInitialized)
                    {
                        isInitialized = true;

                        ::ShowWindow(window, SW_SHOWNORMAL);
                        ::UpdateWindow(window);
                        ::SetFocus(window);

                        throwIfFailed(controller->put_IsVisible(TRUE));

                        RECT rect;
                        ::GetClientRect(window, &rect);
                        throwIfFailed(controller->put_Bounds(rect));
                    }
                    return S_OK;
                })
                .Get(),
            &eventToken));

        throwIfFailed(webview->add_WebMessageReceived(
            Callback<ICoreWebView2WebMessageReceivedEventHandler>([this](ICoreWebView2* sender,
                                                                         ICoreWebView2WebMessageReceivedEventArgs* args)
                                                                      -> HRESULT {
                LPWSTR buffer;
                throwIfFailed(args->TryGetWebMessageAsString(&buffer));
                std::string const jsonData = internal::toString(buffer);

                simdjson::ondemand::parser parser;
                auto document = parser.iterate(jsonData, jsonData.size() + simdjson::SIMDJSON_PADDING);

                uint64_t index;
                auto error = document["index"].get_uint64().get(index);
                if (error != simdjson::error_code::SUCCESS)
                {
                    ::CoTaskMemFree(buffer);
                    return S_OK;
                }

                std::string_view functionName;
                error = document["func"].get_string().get(functionName);
                if (error != simdjson::error_code::SUCCESS)
                {
                    ::CoTaskMemFree(buffer);
                    return S_OK;
                }

                std::string_view argumentData;
                error = document["args"].raw_json().get(argumentData);
                if (error != simdjson::error_code::SUCCESS)
                {
                    ::CoTaskMemFree(buffer);
                    return S_OK;
                }

                auto found = bindCallbacks.find(std::string(functionName));
                if (found != bindCallbacks.end())
                {
                    found->second(index, argumentData);
                }

                ::CoTaskMemFree(buffer);
                return S_OK;
            }).Get(),
            &eventToken));

        winrt::com_ptr<ICoreWebView2Settings> settings;
        throwIfFailed(webview->get_Settings(settings.put()));

        throwIfFailed(settings->put_AreDevToolsEnabled(debugMode ? TRUE : FALSE));
        throwIfFailed(settings->put_AreDefaultContextMenusEnabled(debugMode ? TRUE : FALSE));
    }

    auto Edge::setWindowMaxSize(uint32_t const width, uint32_t const height) -> void
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

        maxSize = {.width = width * static_cast<uint32_t>(scaleFactor) / 100,
                   .height = height * static_cast<uint32_t>(scaleFactor) / 100};
    }

    auto Edge::setWindowMinSize(uint32_t const width, uint32_t const height) -> void
    {
        minSize = {.width = width * static_cast<uint32_t>(scaleFactor) / 100,
                   .height = height * static_cast<uint32_t>(scaleFactor) / 100};
    }

    auto Edge::setWindowSize(uint32_t const width, uint32_t const height) -> void
    {
        ::SetWindowPos(window, nullptr, CW_USEDEFAULT, CW_USEDEFAULT, width * static_cast<uint32_t>(scaleFactor) / 100,
                       height * static_cast<uint32_t>(scaleFactor) / 100, SWP_NOMOVE);
    }

    auto Edge::run(std::string_view const urlPath) -> void
    {
        throwIfFailed(webview->AddScriptToExecuteOnDocumentCreated(
            internal::toWString(std::vformat(js::onLoadHTMLInjection, std::make_format_args("window.chrome.webview")))
                .c_str(),
            nullptr));

        if (urlPath.starts_with("http://") || urlPath.starts_with("https://"))
        {
            throwIfFailed(webview->Navigate(internal::toWString(urlPath).c_str()));
        }
        else
        {
            std::filesystem::path const currentPath = std::filesystem::current_path();
            throwIfFailed(
                webview->Navigate(internal::toWString("file:///" + (currentPath / urlPath).generic_string()).c_str()));
        }

        MSG msg;
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
                if (idleCallback)
                {
                    idleCallback();
                }
            }
        }

        throwIfFailed(controller->Close());
    }

    auto Edge::executeJavaScript(std::string_view const executeCode) -> void
    {
        throwIfFailed(webview->ExecuteScript(internal::toWString(executeCode).c_str(), nullptr));
    }

    auto Edge::quit() -> void
    {
        ::PostQuitMessage(0);
    }

    auto Edge::showSaveDialog(std::filesystem::path const& initialPath, std::string_view const filter)
        -> std::optional<std::filesystem::path>
    {
        winrt::com_ptr<IFileDialog> fileDialog;
        throwIfFailed(CoCreateInstance(CLSID_FileSaveDialog, nullptr, CLSCTX_INPROC_SERVER, __uuidof(IFileDialog),
                                       fileDialog.put_void()));

        DWORD flags;
        throwIfFailed(fileDialog->GetOptions(&flags));
        throwIfFailed(fileDialog->SetOptions(flags | FOS_FORCEFILESYSTEM));

        std::wstring const currentFolderPath = internal::toWString(initialPath.string());
        winrt::com_ptr<IShellItem> currentFolder;

        throwIfFailed(SHCreateItemFromParsingName(currentFolderPath.c_str(), NULL, __uuidof(IShellItem),
                                                  currentFolder.put_void()));
        throwIfFailed(fileDialog->SetDefaultFolder(currentFolder.get()));

        auto const fileTypes = internal::split(std::string(filter), "|");

        std::vector<std::wstring> wFilterTypes(fileTypes.size());
        std::vector<COMDLG_FILTERSPEC> filterSpecs;
        if (fileTypes.size() % 2 == 0)
        {
            for (uint32_t const i : std::views::iota(0u, wFilterTypes.size()))
            {
                wFilterTypes[i] = internal::toWString(fileTypes[i]);
            }

            for (size_t i = 0; i < fileTypes.size(); i += 2)
            {
                filterSpecs.emplace_back(wFilterTypes[i].c_str(), wFilterTypes[i + 1].c_str());
            }

            throwIfFailed(fileDialog->SetFileTypes(static_cast<uint32_t>(filterSpecs.size()), filterSpecs.data()));
        }
        else
        {
            filterSpecs.emplace_back(COMDLG_FILTERSPEC{L"All files (*.*)", L"*.*"});
            throwIfFailed(fileDialog->SetFileTypes(static_cast<uint32_t>(filterSpecs.size()), filterSpecs.data()));
        }

        HRESULT hr = fileDialog->Show(window);
        if (SUCCEEDED(hr))
        {
            winrt::com_ptr<IShellItem> result;

            hr = fileDialog->GetResult(result.put());
            if (SUCCEEDED(hr))
            {
                PWSTR selectFilePath;
                throwIfFailed(result->GetDisplayName(SIGDN_FILESYSPATH, &selectFilePath));

                uint32_t typeIndex;
                throwIfFailed(fileDialog->GetFileTypeIndex(&typeIndex));

                std::string extPath = internal::toString(filterSpecs[typeIndex - 1].pszSpec);
                if (extPath.compare("*.*") == 0)
                {
                    extPath = "";
                }
                else
                {
                    extPath = extPath.substr(1, extPath.size());
                }

                std::filesystem::path const outPath = internal::toString(selectFilePath) + extPath;

                ::CoTaskMemFree(selectFilePath);
                return outPath;
            }
            else
            {
                return std::nullopt;
            }
        }
        return std::nullopt;
    }

    auto showMessageDialog(std::string_view const title, std::string_view const message,
                           MessageDialogType const messageType) -> void
    {
        PCWSTR iconPath = nullptr;
        switch (messageType)
        {
            case MessageDialogType::Information: {
                iconPath = TD_INFORMATION_ICON;
                break;
            }
            case MessageDialogType::Warning: {
                iconPath = TD_WARNING_ICON;
                break;
            }
            case MessageDialogType::Error: {
                iconPath = TD_ERROR_ICON;
                break;
            }
        }

        throwIfFailed(TaskDialog(nullptr, nullptr, internal::toWString(title).c_str(), nullptr,
                                 internal::toWString(message).c_str(), TDCBF_OK_BUTTON, iconPath, nullptr));
    }
} // namespace libwebview