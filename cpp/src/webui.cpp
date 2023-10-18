#include "precompiled.h"
#include "webui.h"

CWebUI create_web_ui(
    char const* app_name,
    char const* title, 
    uint32_t const width, 
    uint32_t const height, 
    bool const resizeable,
    bool const is_debug
) {
    try {
        auto web_ui = new WebUIPlatform(app_name, title, { width, height }, resizeable, is_debug);
        return web_ui;
    } catch(std::runtime_error e) {
        return nullptr;
    }
}

void delete_web_ui(CWebUI web_ui) {
    delete web_ui;
}

void web_ui_run(CWebUI web_ui, char const* index_file) {
    reinterpret_cast<WebUIPlatform*>(web_ui)->run(index_file);
}

void web_ui_bind(CWebUI web_ui, char const* func_name, void(*callback)(void*, uint64_t, char const*), void* args) {
    reinterpret_cast<WebUIPlatform*>(web_ui)->bind(func_name, [callback, args](uint64_t const index, std::string_view const data) { callback(args, index, data.data()); });
}

void web_ui_result(CWebUI web_ui, uint64_t index, bool success, char const* data) {
    reinterpret_cast<WebUIPlatform*>(web_ui)->result(index, success, data);
}

void web_ui_quit(CWebUI web_ui) {
    reinterpret_cast<WebUIPlatform*>(web_ui)->quit();
}

void web_ui_set_max_size(CWebUI web_ui, uint32_t const width, uint32_t const height) {
    reinterpret_cast<WebUIPlatform*>(web_ui)->set_max_size({ width, height });
}

void web_ui_set_min_size(CWebUI web_ui, uint32_t const width, uint32_t const height) {
    reinterpret_cast<WebUIPlatform*>(web_ui)->set_min_size({ width, height });
}

void web_ui_execute_js(CWebUI web_ui, char const* js) {
    reinterpret_cast<WebUIPlatform*>(web_ui)->execute_js(js);
}
