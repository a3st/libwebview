#pragma once

#define NOMINMAX
#include <Windows.h>
#undef NOMINMAX
#include <dwmapi.h>
#include <winrt/base.h>
#include <webview2/WebView2.h>

using bind_func_t = std::function<void(uint64_t const, std::string_view const)>;

class WebUIEdge {
public:

    WebUIEdge(
        std::string_view const title, 
        std::tuple<uint32_t, uint32_t> const size, 
        bool const resizeable,
        std::tuple<uint32_t, uint32_t> const min_size,
        std::tuple<uint32_t, uint32_t> const max_size,
        bool const is_debug
    );

    auto run(std::string_view const index_file) -> void;

    auto bind(std::string_view const func_name, bind_func_t&& callback) -> void;

    auto execute_js(std::string_view const js) -> void;

    auto result(uint64_t const index, bool const success, std::string_view const data) -> void;

    auto quit() -> void;

private:

    HWND window;
    winrt::com_ptr<ICoreWebView2Environment> environment;
    winrt::com_ptr<ICoreWebView2Controller> controller;
    winrt::com_ptr<ICoreWebView2> webview;
    EventRegistrationToken token;
    bool is_initialized;
    DWORD main_thread_id;
    std::binary_semaphore semaphore;
    std::tuple<uint32_t, uint32_t> min_window_size;
    std::tuple<uint32_t, uint32_t> max_window_size;
    std::map<std::string, bind_func_t> js_callbacks;

    static auto window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT;

    auto navigation_completed(ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT;
    
    auto web_message_received(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT;
};