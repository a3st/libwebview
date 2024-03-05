// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

#include "platform.hpp"
#define NOMINMAX
#include <Windows.h>
#undef NOMINMAX
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
        Edge(std::string_view const app_name, std::string_view const title, uint32_t const width, uint32_t const height,
             bool const resizeable, bool const debug_mode);

        auto set_max_size(uint32_t const width, uint32_t const height) -> void override;

        auto set_min_size(uint32_t const width, uint32_t const height) -> void override;

        auto set_size(uint32_t const width, uint32_t const height) -> void override;

        auto run(std::string_view const url) -> void override;

        auto execute_js(std::string_view const js) -> void override;

        auto quit() -> void override;

      private:
        HWND window;
        DEVICE_SCALE_FACTOR scale;
        uint32_t min_window_width{1};
        uint32_t min_window_height{1};
        uint32_t max_window_width{0};
        uint32_t max_window_height{0};

        winrt::com_ptr<ICoreWebView2Environment> environment;
        winrt::com_ptr<ICoreWebView2Controller> controller;
        winrt::com_ptr<ICoreWebView2> webview;
        EventRegistrationToken token;

        bool is_initialized;
        std::binary_semaphore semaphore;

        static auto window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) -> LRESULT;

        auto navigation_completed(ICoreWebView2* sender, ICoreWebView2NavigationCompletedEventArgs* args) -> HRESULT;

        auto web_message_received(ICoreWebView2* sender, ICoreWebView2WebMessageReceivedEventArgs* args) -> HRESULT;
    };
} // namespace libwebview