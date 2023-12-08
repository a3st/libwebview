#include "precompiled.h"
#include "webview.h"

C_Webview webview_create_app(
    char const* app_name,
    char const* title, 
    uint32_t const width, 
    uint32_t const height, 
    bool const resizeable,
    bool const is_debug
) {
    try {
        auto impl = new WebviewImpl(app_name, title, { width, height }, resizeable, is_debug);
        return impl;
    } catch(std::runtime_error e) {
        return nullptr;
    }
}

void webview_delete_app(C_Webview instance) {
    delete instance;
}

void webview_run_app(C_Webview instance, char const* file_path) {
    reinterpret_cast<WebviewImpl*>(instance)->run(file_path);
}

void webview_quit_app(C_Webview instance) {
    reinterpret_cast<WebviewImpl*>(instance)->quit();
}

void webview_set_max_size_app(C_Webview instance, uint32_t const width, uint32_t const height) {
    reinterpret_cast<WebviewImpl*>(instance)->set_max_size({ width, height });
}

void webview_set_min_size_app(C_Webview instance, uint32_t const width, uint32_t const height) {
    reinterpret_cast<WebviewImpl*>(instance)->set_min_size({ width, height });
}

void webview_set_size_app(C_Webview instance, uint32_t const width, uint32_t const height) {
    reinterpret_cast<WebviewImpl*>(instance)->set_size({ width, height });
}

void webview_bind(C_Webview instance, char const* func_name, void(*callback)(void*, uint64_t, char const*), void* context) {
    reinterpret_cast<WebviewImpl*>(instance)->bind(func_name, [callback, context](uint64_t const index, std::string_view const data) { callback(context, index, data.data()); });
}

void webview_result(C_Webview instance, uint64_t index, bool success, char const* data) {
    reinterpret_cast<WebviewImpl*>(instance)->result(index, success, data);
}

void webview_emit(C_Webview instance, char const* event, char const* data) {
    reinterpret_cast<WebviewImpl*>(instance)->emit(event, data);
}