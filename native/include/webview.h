// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

#ifdef WIN32
#define LIB_WEBVIEW_API __declspec(dllexport)
#else
#define LIB_WEBVIEW_API
#endif

extern "C"
{
    typedef void* C_Webview;

    /*!
        \brief Create new application

        \param app_name an application name
        \param title a window title
        \param width a window width
        \param height a window height
        \param resizeable ability to user window resize
        \param debug_mode using WebView Debug Tools
    */
    LIB_WEBVIEW_API C_Webview webview_create_app(char const* app_name, char const* title, uint32_t const width,
                                                 uint32_t const height, bool const resizeable, bool const debug_mode);

    /*!
        \brief Delete application

        \param instance pointer to application
    */
    LIB_WEBVIEW_API void webview_delete_app(C_Webview instance);

    /*!
        \brief Application main loop

        \param instance pointer to application
        \param url_path startup url path (if url starts with https:// or http:// app runs remote resource. Otherwise app
       runs local resource eg. html file)
    */
    LIB_WEBVIEW_API bool webview_run_app(C_Webview instance, char const* url_path);

    /*!
        \brief Quit application

        \param instance pointer to application
    */
    LIB_WEBVIEW_API void webview_quit_app(C_Webview instance);

    /*!
        \brief Set max application window size

        \param instance pointer to application
        \param width a max window width
        \param height a max window height
    */
    LIB_WEBVIEW_API void webview_set_max_size_app(C_Webview instance, uint32_t const width, uint32_t const height);

    /*!
        \brief Set min application window size

        \param instance pointer to application
        \param width a min window width
        \param height a min window height
    */
    LIB_WEBVIEW_API void webview_set_min_size_app(C_Webview instance, uint32_t const width, uint32_t const height);

    /*!
        \brief Set new application window size

        \param instance pointer to application
        \param width a new window width
        \param height a new window height
    */
    LIB_WEBVIEW_API void webview_set_size_app(C_Webview instance, uint32_t const width, uint32_t const height);

    /*!
        \brief Bind function for call from JS

        \param instance pointer to application
        \param name a function name
        \param function a binded callback (context, index, data) -> void
    */
    LIB_WEBVIEW_API bool webview_bind(C_Webview instance, char const* name,
                                      void (*function)(void*, uint64_t, char const*), void* context);

    /*!
        \brief Return result to JS function

        \param instance pointer to application
        \param index a function index
        \param success a success or fail return
        \param data a data return
    */
    LIB_WEBVIEW_API void webview_result(C_Webview instance, uint64_t index, bool success, char const* data);

    /*!
        \brief Set application idle callback

        \param instance pointer to application
        \param function a idle callback (context)
    */
    LIB_WEBVIEW_API void webview_set_idle_callback(C_Webview instance, void (*function)(void*), void* context);
}