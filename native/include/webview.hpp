// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

#include "platform.hpp"

namespace libwebview
{
    struct EventArgs
    {
        uint64_t index;
    };

    class App
    {
      public:
        App(std::string_view const appName, std::string_view const title, uint32_t const width, uint32_t const height,
            bool const resizeable, bool const debugMode)
        {
            platform = std::make_unique<Platform>(appName, title, width, height, resizeable, debug_mode);
        }

        auto quit() -> void
        {
            platform->quit();
        }

        auto run(std::string_view const urlPath) -> void
        {
            platform->run(urlPath);
        }

        auto setWindowSize(uint32_t const width, uint32_t const height) -> void
        {
            platform->setWindowSize(width, height);
        }

        auto setMinWindowSize(uint32_t const width, uint32_t const height) -> void
        {
            platform->setMinWindowSize(width, height);
        }

        auto setMaxWindowSize(uint32_t const width, uint32_t const height) -> void
        {
            platform->setMaxWindowSize(width, height);
        }

        template <typename... Args>
        auto bind(std::string_view const functionName,
                  std::function<void(EventArgs const&, Args...)>&& function) -> void
        {
            platform->bind(functionName, [](uint64_t const index, std::string_view const data) {
                simdjson::ondemand::parser parser;
                auto document = parser.iterate(data, data.size() + simdjson::SIMDJSON_PADDING);
            });

            /*struct BindedContext
            {
                std::function<void(EventArgs const&, Args...)> callback;
            };
            auto context = new BindedContext{.callback = callback};

            return webview_bind(
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
            */
        }

        auto bind(std::string_view const functionName, std::function<void(EventArgs const&)>&& function) -> bool
        {
            platform->bind(functionName, [function](uint64_t const index, std::string_view const data) {
                function(EventArgs{.index = index});
            });
        }

        auto emit(std::string_view const eventName, std::string_view const data) -> void
        {
            platform->emit(eventName, data);
        }

        auto result(uint64_t const index, bool const success, std::string_view const data) -> void
        {
            platform->result(index, success, data);
        }

        auto setIdle(std::function<idle_func_t>&& function) -> void
        {
            platform->setIdle(functionName, std::move(function));
        }

      private:
        std::unique_ptr<Platform> platform;
    };
} // namespace libwebview