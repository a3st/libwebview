// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "platform/webkit.hpp"
#include "precompiled.h"

namespace libwebview
{
    WebKit::WebKit(std::string_view const appName, std::string_view const title, uint32_t const width,
                   uint32_t const height, bool const resizeable, bool const debugMode)
        : appName(appName)
    {
        gtk_init();

        window = GTK_WINDOW(gtk_window_new());
        gtk_window_set_title(window, std::string(title).c_str());
        gtk_window_set_default_size(window, width, height);
        gtk_window_set_resizable(window, resizeable);

        webview = reinterpret_cast<WebKitWebView*>(webkit_web_view_new());
        gtk_window_set_child(window, GTK_WIDGET(webview));
    }

    auto WebKit::setWindowMaxSize(uint32_t const width, uint32_t const height) -> void
    {
    }

    auto WebKit::setWindowMinSize(uint32_t const width, uint32_t const height) -> void
    {
    }

    auto WebKit::setWindowSize(uint32_t const width, uint32_t const height) -> void
    {
    }

    auto WebKit::run(std::string_view const urlPath) -> void
    {
        if (urlPath.starts_with("http://") || urlPath.starts_with("https://"))
        {
            webkit_web_view_load_uri(webview, std::string(urlPath).c_str());
        }
        else
        {
            std::filesystem::path const currentPath = std::filesystem::current_path();
            webkit_web_view_load_uri(webview, ("file:///" + (currentPath / urlPath).generic_string()).c_str());
        }

        bool running = true;

        g_signal_connect(window, "destroy", G_CALLBACK(*[](GtkWidget* widget, gpointer userData) {
                             auto running = reinterpret_cast<bool*>(userData);
                             (*running) = false;
                         }),
                         &running);

        gtk_window_present(window);

        while (running)
        {
            g_main_context_iteration(nullptr, false);
            if (idleCallback)
            {
                idleCallback();
            }
        }
    }

    auto WebKit::executeJavaScript(std::string_view const executeCode) -> void
    {
    }

    auto WebKit::quit() -> void
    {
    }

    auto WebKit::showSaveDialog(std::filesystem::path const& initialPath,
                                std::string_view const filter) -> std::optional<std::filesystem::path>
    {
        return std::nullopt;
    }

    auto showMessageDialog(std::string_view const title, std::string_view const message,
                           MessageDialogType const messageType) -> void
    {
    }
} // namespace libwebview