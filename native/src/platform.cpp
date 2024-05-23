// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "platform.hpp"
#include "injection.hpp"
#include "precompiled.h"

#ifdef LIB_WEBVIEW_EDGE
#include "platform/edge.hpp"
#endif

namespace libwebview
{
    auto Platform::createInstance(std::string_view const appName, std::string_view const title, uint32_t const width,
                                  uint32_t const height, bool const resizeable,
                                  bool const debugMode) -> std::unique_ptr<Platform>
    {
<<<<<<< Updated upstream
        Platform* platform = nullptr;
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
=======
#ifdef LIB_WEBVIEW_EDGE
        return std::make_unique<Edge>(appName, title, width, height, resizeable, debugMode);
#else
#error libwebview target platform is not defined
        return nullptr;
#endif
    }

    auto Platform::bind(std::string_view const functionName, bind_func_t&& callback) -> void
>>>>>>> Stashed changes
    {
        if (callbacks.find(std::string(functionName)) != callbacks.end())
        {
            throw std::runtime_error("Cannot to bind a function that already exists");
        }
<<<<<<< Updated upstream
        callbacks.insert({std::string(func), std::make_pair(std::move(callback), context)});
    }

    auto Platform::unbind(std::string_view const func) -> void
    {
        auto result = callbacks.find(std::string(func));
        if (result == callbacks.end())
        {
            throw std::runtime_error("Cannot to unbind a function that no exists");
        }
        delete result->second.second;
        callbacks.erase(result);
=======
        callbacks.emplace(std::string(functionName), std::move(callback));
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
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

    auto Platform::set_idle(idle_func_t&& callback, void* context) -> void
    {
        if (idle.first && idle.second)
        {
            delete idle.second;
        }

        idle = std::make_pair(std::move(callback), context);
=======
        this->executeJavaScript(std::format(executeCode, index, data));
>>>>>>> Stashed changes
    }
} // namespace libwebview