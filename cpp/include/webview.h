#pragma once

#define NOMINMAX
#include "Windows.h"
#include <webview2/WebView2.h>
#include <winrt/base.h>
#undef NOMINMAX
#define PICOJSON_USE_INT64
#include <picojson/picojson.h>
#include <thread-pool/BS_thread_pool.hpp>

namespace elbot {

namespace webview {

class Webview;

enum class PromiseResultType {
    Resolve,
    Reject
};

struct PromiseResult {
    PromiseResultType type;
    picojson::value message;
};

using bind_func_t = std::function<PromiseResult(Webview&, picojson::value const&)>;

class Api {
    friend class Webview;
public:

    Api() = default;

    auto add_func(std::string_view const name, bind_func_t const& func) -> void;

private:
    std::map<std::string, bind_func_t> functions;
};

class Webview {
public:

    Webview(
        std::string_view const title, 
        std::string_view const url, 
        uint32_t const width, 
        uint32_t const height, 
        std::filesystem::path const& user_data,
        std::string_view const app_name,
        Api& api,
        bool is_debug
    );
    
    auto run() -> void;

    auto terminate() -> void;

    auto execute_js(std::string_view const js) -> void;

private:

    HWND window;
    winrt::com_ptr<ICoreWebView2Environment> environment;
    winrt::com_ptr<ICoreWebView2Controller> controller;
    winrt::com_ptr<ICoreWebView2> webview;
    EventRegistrationToken token;
    bool is_initialized;
    DWORD main_thread_id;
    std::map<std::string, bind_func_t> callbacks;
    BS::thread_pool thread_pool;

    static auto webview_window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT;
};

}

}