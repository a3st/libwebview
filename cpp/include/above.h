// Copyright © 2022-2023 Dmitriy Lukovenko. All rights reserved.

#pragma once

template<typename Backend>
class Above : public Backend {
public:
    Above(
        std::string_view const app_name,
        std::string_view const title, 
        std::tuple<uint32_t, uint32_t> const size, 
        bool const resizeable,
        bool const is_debug
    ) : Backend(app_name, title, size, resizeable, is_debug) { }
};

#ifdef ABOVE_EDGE
#include "platform/above_edge.h"
using AbovePlatform = Above<AboveEdge>;
#endif

#ifdef WIN32
#define ABOVE_API __declspec(dllexport)
#else
#define ABOVE_API 
#endif

extern "C" {

typedef void* C_Above;

//! Create new application
/*!
    \param app_name an application name 
    \param title a window title
    \param width a window width
    \param height a window height
    \param resizeable ability to user window resize
    \param is_debug using WebView Debug Tools
*/
ABOVE_API C_Above above_create_app(
    char const* app_name,
    char const* title, 
    uint32_t const width, 
    uint32_t const height, 
    bool const resizeable,
    bool const is_debug
);

//! Delete application
/*!
    \param instance pointer to application
*/
ABOVE_API void above_delete_app(C_Above instance);

//! Application main loop
/*!
    \param instance pointer to application
    \param file_path startup WebView html file
*/
ABOVE_API void above_run_app(C_Above instance, char const* file_path);

//! Quit application
/*!
    \param instance pointer to application
*/
ABOVE_API void above_quit_app(C_Above instance);

//! Set max application window size
/*!
    \param instance pointer to application
    \param width a max window width
    \param height a max window height
*/
ABOVE_API void above_set_max_size_app(C_Above instance, uint32_t const width, uint32_t const height);

//! Set min application window size
/*!
    \param instance pointer to application
    \param width a min window width
    \param height a min window height
*/
ABOVE_API void above_set_min_size_app(C_Above instance, uint32_t const width, uint32_t const height);

//! Set new application window size
/*!
    \param instance pointer to application
    \param width a new window width
    \param height a new window height
*/
ABOVE_API void above_set_size_app(C_Above instance, uint32_t const width, uint32_t const height);

//! Bind function for call from JS
/*!
    \param instance pointer to application
    \param func_name a function name
    \param callback a binded callback (context, index, data) -> void
*/
ABOVE_API void above_bind(C_Above instance, char const* func_name, void(*callback)(void*, uint64_t, char const*), void* context);

//! Return result to JS function
/*!
    \param instance pointer to application
    \param index a function index
    \param success a success or fail return
    \param data a data return
*/
ABOVE_API void above_result(C_Above instance, uint64_t index, bool success, char const* data);

//! Emit event from JS
/*!
    \param instance pointer to application
    \param event a event name
    \param data a event data
*/
ABOVE_API void above_emit(C_Above instance, char const* event, char const* data);

}