// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

#include "platform.hpp"
#include <adwaita.h>
#include <gtk/gtk.h>
#include <webkit/webkit.h>

namespace libwebview
{
    class WebKit final : public Platform
    {
      public:
        WebKit(std::string_view const appName, std::string_view const title, uint32_t const width,
               uint32_t const height, bool const resizeable, bool const debugMode);

        auto setWindowMaxSize(uint32_t const width, uint32_t const height) -> void override;

        auto setWindowMinSize(uint32_t const width, uint32_t const height) -> void override;

        auto setWindowSize(uint32_t const width, uint32_t const height) -> void override;

        auto run(std::string_view const urlPath) -> void override;

        auto executeJavaScript(std::string_view const executeCode) -> void override;

        auto quit() -> void override;

        auto showSaveDialog(std::filesystem::path const& initialPath,
                            std::string_view const filter) -> std::optional<std::filesystem::path> override;

      private:
        GtkWindow* window;
        WebKitWebView* webview;

        std::string appName;

        struct WindowSize
        {
            uint32_t width;
            uint32_t height;
        };

        WindowSize minSize;
        WindowSize maxSize;

        bool isInitialized;
        std::binary_semaphore semaphore;
    };
} // namespace libwebview