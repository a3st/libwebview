// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

namespace libwebview
{
    using bind_func_t = std::function<void(uint64_t const, std::string_view const)>;
    using custom_update_func_t = std::function<void()>;

    enum class PlatformType
    {
        Edge,
        WebKit,
        CEF
    };

    class Platform
    {
      public:
        static auto create(std::string_view const app_name, std::string_view const title, uint32_t const width,
                           uint32_t const height, bool const resizeable, bool const is_debug,
                           PlatformType const platform_type) -> Platform*;

        virtual auto set_max_size(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto set_min_size(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto set_size(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto run(std::string_view const url) -> void = 0;

        virtual auto run(std::string_view const url, custom_update_func_t&& callback) -> void = 0;

        virtual auto bind(std::string_view const func_name, bind_func_t&& callback) -> void = 0;

        virtual auto execute_js(std::string_view const js) -> void = 0;

        virtual auto result(uint64_t const index, bool const success, std::string_view const data) -> void = 0;

        virtual auto quit() -> void = 0;

        virtual auto emit(std::string_view const event, std::string_view const data) -> void = 0;
    };
} // namespace libwebview