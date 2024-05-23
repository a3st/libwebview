// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

<<<<<<< Updated upstream
#include "concurrent_queue.hpp"

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

=======
namespace libwebview
{
>>>>>>> Stashed changes
    class Platform
    {
      public:
        using bind_func_t = std::function<void(uint64_t const, std::string_view const)>;

        static auto createInstance(std::string_view const appName, std::string_view const title, uint32_t const width,
                                   uint32_t const height, bool const resizeable,
                                   bool const debugMode) -> std::unique_ptr<Platform>;

        virtual auto setWindowMaxSize(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto setWindowMinSize(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto setWindowSize(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto run(std::string_view const urlPath) -> void = 0;

        virtual auto executeJavaScript(std::string_view const executeCode) -> void = 0;

        virtual auto quit() -> void = 0;

<<<<<<< Updated upstream
        auto bind(std::string_view const func, bind_func_t&& callback, void* context) -> void;

        auto unbind(std::string_view const func) -> void;

        auto result(uint64_t const index, bool const success, std::string_view const data) -> void;

        auto emit(std::string_view const event, std::string_view const data) -> void;

        auto invoke(invoke_func_t&& callback, void* context) -> void;

        auto set_idle(idle_func_t&& callback, void* context) -> void;

      protected:
        ConcurrentQueue<std::pair<invoke_func_t, void*>> main_queue;
        std::map<std::string, std::pair<bind_func_t, void*>> callbacks;
        std::pair<idle_func_t, void*> idle;
=======
        auto bind(std::string_view const functionName, bind_func_t&& callback) -> void;

        auto result(uint64_t const index, bool const success, std::string_view const data) -> void;

      protected:
        std::unordered_map<std::string, bind_func_t> callbacks;
>>>>>>> Stashed changes
    };
} // namespace libwebview