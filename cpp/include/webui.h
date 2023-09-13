#pragma once

template<typename Backend>
class WebUI : public Backend {
public:
    WebUI(
        std::string_view const title, 
        std::tuple<uint32_t, uint32_t> const size, 
        bool const resizeable,
        std::tuple<uint32_t, uint32_t> const min_size,
        std::tuple<uint32_t, uint32_t> const max_size,
        bool const is_debug
    ) : Backend(title, size, resizeable, min_size, max_size, is_debug) { }
};

#ifdef WEBUI_EDGE
#include "platform/webui_edge.h"
using WebUIPlatform = WebUI<WebUIEdge>;
#endif // WEBUI_EDGE

extern "C" {

typedef void* CWebUI;

__declspec(dllexport) CWebUI create_web_ui(
    char const* title, 
    uint32_t const width, 
    uint32_t const height, 
    bool const resizeable,
    uint32_t const min_width,
    uint32_t const min_height,
    uint32_t const max_width,
    uint32_t const max_height,
    bool const is_debug
);

__declspec(dllexport) void web_ui_run(CWebUI web_ui, char const* index_file);

__declspec(dllexport) void web_ui_bind(CWebUI web_ui, char const* func_name, void(*callback)(void*, char const*), void* args);

}