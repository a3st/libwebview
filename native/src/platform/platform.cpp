// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "platform/platform.hpp"
#include "precompiled.h"

#ifdef LIB_WEBVIEW_EDGE
#include "platform/edge.hpp"
#endif

namespace libwebview
{
    auto Platform::create(std::string_view const app_name, std::string_view const title, uint32_t const width,
                          uint32_t const height, bool const resizeable, bool const debug_mode,
                          PlatformType const platform_type) -> Platform*
    {
        Platform* platform;
        switch (platform_type)
        {
            case PlatformType::Edge: {
                platform = new Edge(app_name, title, width, height, resizeable, debug_mode);
                break;
            }
            default: {
                break;
            }
        }
        return platform;
    }
} // namespace libwebview