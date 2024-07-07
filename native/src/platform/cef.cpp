// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "platform/cef.hpp"
#include "precompiled.h"

namespace libwebview
{
    CEF::CEF(std::string_view const appName, std::string_view const title, uint32_t const width, uint32_t const height,
             bool const resizeable, bool const debugMode)
    {
    }

    auto CEF::setWindowMaxSize(uint32_t const width, uint32_t const height) -> void
    {
    }

    auto CEF::setWindowMinSize(uint32_t const width, uint32_t const height) -> void
    {
    }

    auto CEF::setWindowSize(uint32_t const width, uint32_t const height) -> void
    {
    }

    auto CEF::run(std::string_view const urlPath) -> void
    {
    }

    auto CEF::executeJavaScript(std::string_view const executeCode) -> void
    {
    }

    auto CEF::quit() -> void
    {
    }

    auto CEF::showSaveDialog(std::filesystem::path const& initialPath,
                             std::string_view const filter) -> std::optional<std::filesystem::path>
    {
        return std::nullopt;
    }

    auto showMessageDialog(std::string_view const title, std::string_view const message,
                           MessageDialogType const messageType) -> void
    {
    }
} // namespace libwebview