// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

#include "webview.h"
#include <nlohmann/json.hpp>

namespace libwebview
{
    struct EventArgs
    {
        uint64_t index;
    };

    class App
    {
      public:
        App(std::string_view const app_name, std::string_view const title, uint32_t const width, uint32_t const height,
            bool const resizeable, bool const debug_mode)
        {
            app = webview_create_app(std::string(app_name).c_str(), std::string(title).c_str(), width, height,
                                     resizeable, debug_mode);
        }

        ~App()
        {
            webview_delete_app(app);
        }

        auto quit() -> void
        {
            webview_quit_app(app);
        }

        auto run(std::string_view const url) -> void
        {
            webview_run_app(app, std::string(url).c_str());
        }

        auto set_size(uint32_t const width, uint32_t const height) -> void
        {
            webview_set_size_app(app, width, height);
        }

        auto set_min_size(uint32_t const width, uint32_t const height) -> void
        {
            webview_set_min_size_app(app, width, height);
        }

        auto set_max_size(uint32_t const width, uint32_t const height) -> void
        {
            webview_set_max_size_app(app, width, height);
        }

        template <typename... Args>
        auto bind(std::string_view const name, std::function<void(EventArgs const&, Args...)>&& callback)
        {
            struct BindedContext
            {
                std::function<void(EventArgs const&, Args...)> callback;
            };
            auto context = new BindedContext{.callback = callback};

            webview_bind(
                app, std::string(name).c_str(),
                [](void* context, uint64_t const index, char const* data) {
                    auto args_data = nlohmann::json::parse(data);
                    auto invoke_helper = [&]<size_t... I>(nlohmann::json_abi_v3_11_2::json const& data,
                                                          std::index_sequence<I...>) {
                        reinterpret_cast<BindedContext*>(context)->callback(EventArgs{.index = index}, data[I]...);
                    };
                    invoke_helper(args_data, std::index_sequence_for<Args...>{});
                },
                context);
        }

        auto invoke(std::function<void()>&& callback)
        {
            struct InvokedContext
            {
                std::function<void()> callback;
            };
            InvokedContext context{.callback = callback};

            webview_invoke(
                app, [](void* context) { reinterpret_cast<InvokedContext*>(context)->callback(); }, &context);
        }

        auto emit(std::string_view const event, std::string_view const data)
        {
            webview_emit(app, std::string(event).c_str(), std::string(data).c_str());
        }

        auto result(uint64_t const index, bool const success, std::string_view const data)
        {
            webview_result(app, index, success, std::string(data).c_str());
        }

      private:
        C_Webview app;
    };
} // namespace libwebview