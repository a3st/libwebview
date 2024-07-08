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
        /*GtkApplication* application = gtk_application_new(std::string(appName).c_str(), G_APPLICATION_DEFAULT_FLAGS);

        g_signal_connect(application, "activate", G_CALLBACK(*[](GtkApplication* application, gpointer userData) {
                             auto platformInstance = reinterpret_cast<WebKit*>(userData);

                             if (!platformInstance)
                             {
                                 return;
                             }

                             gtk_application_add_window(application, platformInstance->window);
                         }),
                         this);

        g_application_run(G_APPLICATION(application), 0, nullptr);*/

        gtk_window_present(window);

        bool running = true;
        while (running)
        {
            

            g_main_context_iteration(nullptr, true);
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