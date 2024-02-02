// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "platform/platform.hpp"
#include "precompiled.h"

#ifdef LIB_WEBVIEW_EDGE
#include "platform/edge.hpp"
#endif

namespace libwebview
{
    auto Platform::create(std::string_view const app_name, std::string_view const title, uint32_t const width,
                          uint32_t const height, bool const resizeable, bool const is_debug,
                          PlatformType const platform_type) -> Platform*
    {
        Platform* platform = nullptr;

        switch (platform_type)
        {
            case PlatformType::Edge: {
                platform = new Edge(app_name, title, width, height, resizeable, is_debug);
                break;
            }
            default: {
                break;
            }
        }
        return platform;
    }
} // namespace libwebview