// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

#include "platform.hpp"

namespace libwebview
{
    class CEF final : public Platform
    {
      public:
        CEF(std::string_view const appName, std::string_view const title, uint32_t const width, uint32_t const height,
            bool const resizeable, bool const debugMode);

        auto setWindowMaxSize(uint32_t const width, uint32_t const height) -> void override;

        auto setWindowMinSize(uint32_t const width, uint32_t const height) -> void override;

        auto setWindowSize(uint32_t const width, uint32_t const height) -> void override;

        auto run(std::string_view const urlPath) -> void override;

        auto executeJavaScript(std::string_view const executeCode) -> void override;

        auto quit() -> void override;

        auto showSaveDialog(std::filesystem::path const& initialPath,
                            std::string_view const filter) -> std::optional<std::filesystem::path> override;

      private:
        struct WindowSize
        {
            uint32_t width;
            uint32_t height;
        };

        WindowSize minSize;
        WindowSize maxSize;

        bool isInitialized;
    };
} // namespace libwebview