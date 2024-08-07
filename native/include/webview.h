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
        \brief Creates the new application
        \param app_name an application name
        \param title the window title
        \param width the window width
        \param height the window height
        \param resizeable allows the user to window resize
        \param debug_mode enables the WebView Debug Tools
    */
    LIB_WEBVIEW_API C_Webview webview_create_app(char const* app_name, char const* title, uint32_t const width,
                                                 uint32_t const height, bool const resizeable, bool const debug_mode);

    /*!
        \brief Deletes the application
        \param instance pointer to the application
    */
    LIB_WEBVIEW_API void webview_delete_app(C_Webview instance);

    /*!
        \brief Runs the application's main loop
        \param instance pointer to the application
        \param url_path the startup URL path (if URL starts with https:// or http://, the app runs a remote resource.
       Otherwise, the app runs a local resource)
    */
    LIB_WEBVIEW_API bool webview_run_app(C_Webview instance, char const* url_path);

    /*!
        \brief Quits the application
        \param instance pointer to the application
    */
    LIB_WEBVIEW_API void webview_quit_app(C_Webview instance);

    /*!
        \brief Sets the application's window maximum size
        \param instance pointer to the application
        \param width the window maximum width
        \param height the window maximum height
    */
    LIB_WEBVIEW_API void webview_set_max_size_app(C_Webview instance, uint32_t const width, uint32_t const height);

    /*!
        \brief Sets the application's window minimum size
        \param instance pointer to the application
        \param width the window minimum width
        \param height the window minimum height
    */
    LIB_WEBVIEW_API void webview_set_min_size_app(C_Webview instance, uint32_t const width, uint32_t const height);

    /*!
        \brief Sets the application's window new size
        \param instance pointer to the application
        \param width the new window width
        \param height the new window height
    */
    LIB_WEBVIEW_API void webview_set_size_app(C_Webview instance, uint32_t const width, uint32_t const height);

    /*!
        \brief Binds the function for call from JavaScript
        \param instance pointer to the application
        \param name the function name
        \param function the binded callback
    */
    LIB_WEBVIEW_API bool webview_bind(C_Webview instance, char const* name,
                                      void (*function)(void*, uint64_t, char const*), void* context);

    /*!
        \brief Returns the result to JavaScript function
        \param instance pointer to the application
        \param index the function index
        \param success returns true when function ended successfully
        \param data data which will return to JavaScript
    */
    LIB_WEBVIEW_API void webview_result(C_Webview instance, uint64_t index, bool success, char const* data);

    /*!
        \brief Sets the application's idle function (at main loop end)
        \param instance pointer to the application
        \param function the binded idle callback
    */
    LIB_WEBVIEW_API void webview_set_idle_callback(C_Webview instance, void (*function)(void*), void* context);

    /*!
        \brief Shows the save dialog box
        \param instance pointer to the application
        \param initial_path the startup directory path
        \param filter the collection of using format filters
    */
    LIB_WEBVIEW_API void webview_show_save_dialog(C_Webview instance, char const* initial_path, char const* filter);
}