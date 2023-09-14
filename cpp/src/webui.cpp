#include "precompiled.h"
#include "webui.h"
#include "platform/webui_edge.h"

CWebUI create_web_ui(
    char const* title, 
    uint32_t const width, 
    uint32_t const height, 
    bool const resizeable,
    uint32_t const min_width,
    uint32_t const min_height,
    uint32_t const max_width,
    uint32_t const max_height,
    bool const is_debug
) {
    std::cout << "Hello world from C++" << std::endl;
    try {
        auto web_ui = new WebUIPlatform(title, { width, height }, resizeable, { min_width, min_height }, { max_width, max_height }, is_debug);
        return web_ui;
    } catch(std::runtime_error e) {
        std::cout << e.what() << std::endl;
        return nullptr;
    }
}


void web_ui_run(CWebUI web_ui, char const* index_file) {
    reinterpret_cast<WebUIPlatform*>(web_ui)->run(index_file);
}


void web_ui_bind(CWebUI web_ui, char const* func_name, void(*callback)(void*, char const*), void* args) {
    reinterpret_cast<WebUIPlatform*>(web_ui)->bind(func_name, [callback, args](std::string_view const data) { callback(args, data.data()); });
}
