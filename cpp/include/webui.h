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

#ifdef WEBUI_WEBKIT
#include "platform/webui_webkit.h"
using WebUIPlatform = WebUI<WebUIWebKit>;
#endif

#ifdef WIN32
#define WEBUI_API __declspec(dllexport)
#else
#define WEBUI_API 
#endif

extern "C" {

typedef void* CWebUI;

WEBUI_API CWebUI create_web_ui(
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

WEBUI_API void delete_web_ui(CWebUI web_ui);

WEBUI_API void web_ui_run(CWebUI web_ui, char const* index_file);

WEBUI_API void web_ui_bind(CWebUI web_ui, char const* func_name, void(*callback)(void*, uint64_t, char const*), void* args);

WEBUI_API void web_ui_result(CWebUI web_ui, uint64_t index, bool success, char const* data);

WEBUI_API void web_ui_quit(CWebUI web_ui);

}