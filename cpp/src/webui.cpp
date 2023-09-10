#include "precompiled.h"
#include "webui.h"
#include "platform/webui_edge.h"

CWebUI create_web_ui(char const* title, uint32_t const width, uint32_t const height) {
    std::cout << "Hello world from C++" << std::endl;
    try {
        auto web_ui = new WebUIPlatform(title, width, height, title);
        return web_ui;
    } catch(std::runtime_error e) {
        std::cout << e.what() << std::endl;
        return nullptr;
    }
}

void web_ui_run(CWebUI web_ui) {
    reinterpret_cast<WebUIPlatform*>(web_ui)->run();
}