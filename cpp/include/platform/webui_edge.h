#pragma once

#include <Windows.h>
#include <dwmapi.h>
#include <winrt/base.h>
#include <webview2/WebView2.h>

class WebUIEdge {
public:

    WebUIEdge(
        std::string_view const title, 
        uint32_t const width, 
        uint32_t const height
    );

    auto run(std::string_view const index_file) -> void;

private:

    HWND window;
    winrt::com_ptr<ICoreWebView2Environment> environment;
    winrt::com_ptr<ICoreWebView2Controller> controller;
    winrt::com_ptr<ICoreWebView2> webview;
    EventRegistrationToken token;
    bool is_initialized;
    std::binary_semaphore semaphore;

    static auto window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT;

    auto navigation_completed(ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT;
    auto web_message_received(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT;
};