#pragma once

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

using bind_func_t = std::function<void(uint64_t const, std::string_view const)>;
using dispatch_func_t = std::function<HRESULT()>;

class Edge {
public:

    Edge(
        std::string_view const app_name,
        std::string_view const title, 
        std::tuple<uint32_t, uint32_t> const size, 
        bool const resizeable,
        bool const is_debug
    );

    auto set_max_size(std::tuple<uint32_t, uint32_t> const size) -> void;

    auto set_min_size(std::tuple<uint32_t, uint32_t> const size) -> void;

    auto set_size(std::tuple<uint32_t, uint32_t> const size) -> void;

    auto run(std::string_view const url) -> void;

    auto bind(std::string_view const func_name, bind_func_t&& callback) -> void;

    auto execute_js(std::string_view const js) -> void;

    auto result(uint64_t const index, bool const success, std::string_view const data) -> void;

    auto quit() -> void;

    auto emit(std::string_view const event, std::string_view const data) -> void;

private:

    HWND window;
    DEVICE_SCALE_FACTOR scale;
    std::tuple<uint32_t, uint32_t> min_window_size;
    std::tuple<uint32_t, uint32_t> max_window_size;

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