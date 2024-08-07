// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "webview.h"
#include "platform.hpp"
#include "precompiled.h"

namespace libwebview
{
    C_Webview webview_create_app(char const* app_name, char const* title, uint32_t const width, uint32_t const height,
                                 bool const resizeable, bool const debug_mode)
    {
        try
        {
            return Platform::create(app_name, title, width, height, resizeable, debug_mode).release();
        }
        catch (std::runtime_error e)
        {
            return nullptr;
        }
    }

    void webview_delete_app(C_Webview instance)
    {
        delete reinterpret_cast<Platform*>(instance);
    }

    bool webview_run_app(C_Webview instance, char const* url_path)
    {
        bool result = true;
        try
        {
            reinterpret_cast<Platform*>(instance)->run(url_path);
        }
        catch (std::runtime_error e)
        {
            result = false;
        }
        return result;
    }

    void webview_quit_app(C_Webview instance)
    {
        reinterpret_cast<Platform*>(instance)->quit();
    }

    void webview_set_max_size_app(C_Webview instance, uint32_t const width, uint32_t const height)
    {
        reinterpret_cast<Platform*>(instance)->setWindowMaxSize(width, height);
    }

    void webview_set_min_size_app(C_Webview instance, uint32_t const width, uint32_t const height)
    {
        reinterpret_cast<Platform*>(instance)->setWindowMinSize(width, height);
    }

    void webview_set_size_app(C_Webview instance, uint32_t const width, uint32_t const height)
    {
        reinterpret_cast<Platform*>(instance)->setWindowSize(width, height);
    }

    bool webview_bind(C_Webview instance, char const* name, void (*function)(void*, uint64_t, char const*),
                      void* context)
    {
        bool result = true;
        try
        {
            reinterpret_cast<Platform*>(instance)->bind(
                name, [function, context](uint64_t const index, std::string_view const data) {
                    function(context, index, data.data());
                });
        }
        catch (std::runtime_error e)
        {
            result = false;
        }
        return result;
    }

    void webview_result(C_Webview instance, uint64_t index, bool success, char const* data)
    {
        reinterpret_cast<Platform*>(instance)->result(index, success, data);
    }

    void webview_set_idle_callback(C_Webview instance, void (*function)(void*), void* context)
    {
        reinterpret_cast<Platform*>(instance)->setIdleCallback([function, context]() { function(context); });
    }

    void webview_show_save_dialog(C_Webview instance, char const* initial_path, char const* filter)
    {
        reinterpret_cast<Platform*>(instance)->showSaveDialog(initial_path, filter);
    }
} // namespace libwebview