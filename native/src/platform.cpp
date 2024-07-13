// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "platform.hpp"
#include "injection.hpp"
#include "precompiled.h"

#ifdef LIB_WEBVIEW_EDGE
#include "platform/edge.hpp"
#elif LIB_WEBVIEW_WEBKIT
#include "platform/webkit.hpp"
#endif

namespace libwebview
{
    auto Platform::create(std::string_view const appName, std::string_view const title, uint32_t const width,
                                  uint32_t const height, bool const resizeable,
                                  bool const debugMode) -> std::unique_ptr<Platform>
    {
#ifdef LIB_WEBVIEW_EDGE
        return std::make_unique<Edge>(appName, title, width, height, resizeable, debugMode);
#elif LIB_WEBVIEW_WEBKIT
        return std::make_unique<WebKit>(appName, title, width, height, resizeable, debugMode);
#else
#error libwebview target platform is not defined
        return nullptr;
#endif
    }

    auto Platform::result(uint64_t const index, bool const success, std::string_view const data) -> void
    {
        std::string executeCode;
        if (success)
        {
            executeCode = js::onResultResolveInjection;
        }
        else
        {
            executeCode = js::onResultRejectInjection;
        }
        this->executeJavaScript(std::vformat(executeCode, std::make_format_args(index, data)));
    }
} // namespace libwebview