// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "platform.hpp"
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

    auto Platform::bind(std::string_view const func, bind_func_t&& callback, void* context) -> void
    {
        if (callbacks.find(std::string(func)) != callbacks.end())
        {
            throw std::runtime_error("Cannot to bind a function that already exists");
        }
        callbacks.insert({std::string(func), std::make_pair(std::move(callback), context)});
    }

    auto Platform::result(uint64_t const index, bool const success, std::string_view const data) -> void
    {
        std::string js;
        if (success)
        {
            js = std::format("webview.results[{0}].resolve({1}); webview.__free_result({0});", index, data);
        }
        else
        {
            js = std::format("webview.results[{0}].reject({1}); webview.__free_result({0});", index, data);
        }
        execute_js(js);
    }

    auto Platform::emit(std::string_view const event, std::string_view const data) -> void
    {
        std::string const js =
            R"(
            if(')" +
            std::string(event) + R"(' in webview.events) {
                webview.events[')" +
            std::string(event) + R"(']()" + std::string(data) + R"()
            }
        )";
        execute_js(js);
    }

    auto Platform::invoke(invoke_func_t&& callback, void* context) -> void
    {
        main_queue.push(std::make_pair(std::move(callback), context));
    }
} // namespace libwebview