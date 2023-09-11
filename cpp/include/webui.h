#pragma once

template<typename Backend>
class WebUI : public Backend {
public:
    WebUI(
        std::string_view const title, 
        uint32_t const width, 
        uint32_t const height
    ) : Backend(title, width, height) { }
};

#ifdef WEBUI_EDGE
#include "platform/webui_edge.h"
using WebUIPlatform = WebUI<WebUIEdge>;
#endif // WEBUI_EDGE

extern "C" {

typedef void* CWebUI;

__declspec(dllexport) CWebUI create_web_ui(char const* title, uint32_t const width, uint32_t const height);
__declspec(dllexport) void web_ui_run(CWebUI web_ui, char const* index_file);

}