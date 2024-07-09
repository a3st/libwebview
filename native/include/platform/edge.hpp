// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

#include "platform.hpp"

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>

#include <ShellScalingApi.h>
#include <dwmapi.h>
#include <webview2/WebView2.h>
#include <webview2/WebView2EnvironmentOptions.h>
#include <winrt/base.h>

namespace libwebview
{
    class Edge final : public Platform
    {
      public:
        Edge(std::string_view const appName, std::string_view const title, uint32_t const width, uint32_t const height,
             bool const resizeable, bool const debugMode);

        auto setWindowMaxSize(uint32_t const width, uint32_t const height) -> void override;

        auto setWindowMinSize(uint32_t const width, uint32_t const height) -> void override;

        auto setWindowSize(uint32_t const width, uint32_t const height) -> void override;

        auto run(std::string_view const urlPath) -> void override;

        auto executeJavaScript(std::string_view const executeCode) -> void override;

        auto quit() -> void override;

        auto showSaveDialog(std::filesystem::path const& initialPath, std::string_view const filter)
            -> std::optional<std::filesystem::path> override;

      private:
        HWND window;
        DEVICE_SCALE_FACTOR scaleFactor;

        struct WindowSize
        {
            uint32_t width;
            uint32_t height;
        };

        WindowSize minSize;
        WindowSize maxSize;

        winrt::com_ptr<ICoreWebView2Environment> environment;
        winrt::com_ptr<ICoreWebView2Controller> controller;
        winrt::com_ptr<ICoreWebView2> webview;
        EventRegistrationToken eventToken;
        bool isInitialized;
        std::binary_semaphore semaphore;

        static auto windowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LRESULT;
    };
} // namespace libwebview