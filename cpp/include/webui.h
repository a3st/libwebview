#pragma once

template<typename Backend>
class WebUI : public Backend {
public:
    WebUI(
        std::string_view const app_name,
        std::string_view const title, 
        std::tuple<uint32_t, uint32_t> const size, 
        bool const resizeable,
        bool const is_debug
    ) : Backend(app_name, title, size, resizeable, is_debug) { }
};

#ifdef WEBUI_EDGE
#include "platform/webui_edge.h"
using WebUIPlatform = WebUI<WebUIEdge>;
#endif // WEBUI_EDGE

#ifdef WIN32
#define WEBUI_API __declspec(dllexport)
#else
#define WEBUI_API 
#endif

extern "C" {

typedef void* CWebUI;

WEBUI_API CWebUI create_web_ui(
    char const* app_name,
    char const* title, 
    uint32_t const width, 
    uint32_t const height, 
    bool const resizeable,
    bool const is_debug
);

WEBUI_API void delete_web_ui(CWebUI web_ui);

WEBUI_API void web_ui_run(CWebUI web_ui, char const* index_file);

WEBUI_API void web_ui_bind(CWebUI web_ui, char const* func_name, void(*callback)(void*, uint64_t, char const*), void* args);

WEBUI_API void web_ui_result(CWebUI web_ui, uint64_t index, bool success, char const* data);

WEBUI_API void web_ui_quit(CWebUI web_ui);

WEBUI_API void web_ui_set_max_size(CWebUI web_ui, uint32_t const width, uint32_t const height);

WEBUI_API void web_ui_set_min_size(CWebUI web_ui, uint32_t const width, uint32_t const height);

WEBUI_API void web_ui_execute_js(CWebUI web_ui, char const* js);

}
