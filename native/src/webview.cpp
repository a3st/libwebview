// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "webview.h"
#include "platform.hpp"
#include "precompiled.h"

using namespace libwebview;

C_Webview webview_create_app(char const* app_name, char const* title, uint32_t const width, uint32_t const height,
                             bool const resizeable, bool const debug_mode)
{
#ifdef LIB_WEBVIEW_EDGE
    PlatformType platform_type = PlatformType::Edge;
#endif
    try
    {
        return Platform::create(app_name, title, width, height, resizeable, debug_mode, platform_type);
    }
    catch (std::runtime_error e)
    {
        return nullptr;
    }
}

void webview_delete_app(C_Webview instance)
{
    delete instance;
}

bool webview_run_app(C_Webview instance, char const* url_path)
{
    try
    {
        reinterpret_cast<Platform*>(instance)->run(url_path);
        return true;
    }
    catch (std::runtime_error e)
    {
        return false;
    }
}

void webview_quit_app(C_Webview instance)
{
    reinterpret_cast<Platform*>(instance)->quit();
}

void webview_set_max_size_app(C_Webview instance, uint32_t const width, uint32_t const height)
{
    reinterpret_cast<Platform*>(instance)->set_max_size(width, height);
}

void webview_set_min_size_app(C_Webview instance, uint32_t const width, uint32_t const height)
{
    reinterpret_cast<Platform*>(instance)->set_min_size(width, height);
}

void webview_set_size_app(C_Webview instance, uint32_t const width, uint32_t const height)
{
    reinterpret_cast<Platform*>(instance)->set_size(width, height);
}

bool webview_bind(C_Webview instance, char const* func, void (*callback)(void*, uint64_t, char const*), void* context)
{
    try
    {
        reinterpret_cast<Platform*>(instance)->bind(
            func,
            [callback, context](uint64_t const index, std::string_view const data) {
                callback(context, index, data.data());
            },
            context);
        return true;
    }
    catch (std::runtime_error e)
    {
        return false;
    }
}

bool webview_unbind(C_Webview instance, char const* func)
{
    try
    {
        reinterpret_cast<Platform*>(instance)->unbind(func);
        return true;
    }
    catch (std::runtime_error e)
    {
        return false;
    }
}

void webview_result(C_Webview instance, uint64_t index, bool success, char const* data)
{
    reinterpret_cast<Platform*>(instance)->result(index, success, data);
}

void webview_emit(C_Webview instance, char const* event, char const* data)
{
    reinterpret_cast<Platform*>(instance)->emit(event, data);
}

void webview_invoke(C_Webview instance, void (*callback)(void*), void* context)
{
    reinterpret_cast<Platform*>(instance)->invoke([callback, context]() { callback(context); }, context);
}

void webview_set_idle(C_Webview instance, void (*callback)(void*), void* context)
{
    reinterpret_cast<Platform*>(instance)->set_idle([callback, context]() { callback(context); }, context);
}