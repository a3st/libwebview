// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

#include "mutex_queue.hpp"

namespace libwebview
{
    using invoke_func_t = std::function<void()>;
    using bind_func_t = std::function<void(uint64_t const, std::string_view const)>;
    using idle_func_t = std::function<void()>;

    enum class PlatformType
    {
        Edge,
        WebKit
    };

    class Platform
    {
      public:
        static auto create(std::string_view const app_name, std::string_view const title, uint32_t const width,
                           uint32_t const height, bool const resizeable, bool const debug_mode,
                           PlatformType const platform_type) -> Platform*;

        virtual auto set_max_size(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto set_min_size(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto set_size(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto run(std::string_view const url_path) -> void = 0;

        virtual auto execute_js(std::string_view const js) -> void = 0;

        virtual auto quit() -> void = 0;

        auto bind(std::string_view const func, bind_func_t&& callback, void* context) -> void;

        auto result(uint64_t const index, bool const success, std::string_view const data) -> void;

        auto emit(std::string_view const event, std::string_view const data) -> void;

        auto invoke(invoke_func_t&& callback, void* context) -> void;

        auto set_idle(idle_func_t&& callback, void* context) -> void;

      protected:
        MutexQueue<std::pair<invoke_func_t, void*>> main_queue;
        std::map<std::string, std::pair<bind_func_t, void*>> callbacks;
        std::pair<idle_func_t, void*> idle;
    };
} // namespace libwebview