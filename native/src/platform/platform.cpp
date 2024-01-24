#include "precompiled.h"
#include "platform/platform.h"

#ifdef LIB_WEBVIEW_EDGE
#include "platform/edge.h"
#endif

auto Platform::create(
    std::string_view const app_name,
    std::string_view const title, 
    uint32_t const width,
    uint32_t const height, 
    bool const resizeable,
    bool const is_debug,
    PlatformType const platform_type
) -> Platform* 
{
    Platform* platform = nullptr;

    switch(platform_type) {
        case PlatformType::Edge: {
            platform = new Edge(app_name, title, width, height, resizeable, is_debug);
        } break;
        default: { } break;
    }
    return platform;
}