#pragma once

#include "platform.h"
#define NOMINMAX
#include <Windows.h>
#undef NOMINMAX
#include <dwmapi.h>
#include <ShellScalingApi.h>
#include <winrt/base.h>
#include <webview2/WebView2.h>
#include <webview2/WebView2EnvironmentOptions.h>
#include "thread_queue.h"
#include "mutex_queue.h"

using dispatch_func_t = std::function<HRESULT()>;

class Edge : public Platform {
public:

    Edge(
        std::string_view const app_name,
        std::string_view const title, 
        uint32_t const width,
        uint32_t const height, 
        bool const resizeable,
        bool const is_debug
    );

    auto set_max_size(uint32_t const width, uint32_t const height) -> void override;

    auto set_min_size(uint32_t const width, uint32_t const height) -> void override;

    auto set_size(uint32_t const width, uint32_t const height) -> void override;

    auto run(std::string_view const url) -> void override;

    auto bind(std::string_view const func_name, bind_func_t&& callback) -> void override;

    auto execute_js(std::string_view const js) -> void override;

    auto result(uint64_t const index, bool const success, std::string_view const data) -> void override;

    auto quit() -> void override;

    auto emit(std::string_view const event, std::string_view const data) -> void override;

private:

    HWND window;
    DEVICE_SCALE_FACTOR scale;
    uint32_t min_window_width{1};
    uint32_t min_window_height{1};
    uint32_t max_window_width{0};
    uint32_t max_window_height{0};

    winrt::com_ptr<ICoreWebView2Environment> environment;
    winrt::com_ptr<ICoreWebView2Controller> controller;
    winrt::com_ptr<ICoreWebView2> webview;
    EventRegistrationToken token;

    bool is_initialized;
    DWORD main_thread_id;
    std::binary_semaphore semaphore;
    ThreadQueue thread_queue;
    MutexQueue<dispatch_func_t> main_queue;

    std::map<std::string, bind_func_t> callbacks;

    static auto window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT;

    auto navigation_completed(ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT;
    
    auto web_message_received(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT;
};