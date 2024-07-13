// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

namespace libwebview
{
    enum class MessageDialogType
    {
        Information,
        Error,
        Warning
    };

    extern auto showMessageDialog(std::string_view const title, std::string_view const message,
                                  MessageDialogType const messageType) -> void;

    class Platform
    {
      public:
        using bind_func_t = std::function<void(uint64_t const, std::string_view const)>;
        using idle_func_t = std::function<void()>;

        virtual ~Platform() = default;

        static auto create(std::string_view const appName, std::string_view const title, uint32_t const width,
                                   uint32_t const height, bool const resizeable,
                                   bool const debugMode) -> std::unique_ptr<Platform>;

        virtual auto setWindowMaxSize(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto setWindowMinSize(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto setWindowSize(uint32_t const width, uint32_t const height) -> void = 0;

        virtual auto run(std::string_view const urlPath) -> void = 0;

        virtual auto executeJavaScript(std::string_view const executeCode) -> void = 0;

        virtual auto quit() -> void = 0;

        template <typename Func>
        auto setIdleCallback(Func&& function) -> void
        {
            idleCallback = [function]() { function(); };
        }

        template <typename Func>
        auto bind(std::string_view const functionName, Func&& function) -> void
        {
            if (bindCallbacks.find(std::string(functionName)) != bindCallbacks.end())
            {
                throw std::runtime_error("Cannot to bind a function that already exists");
            }
            bindCallbacks.emplace(
                std::string(functionName),
                [function](uint64_t const index, std::string_view const arguments) { function(index, arguments); });
        }

        auto result(uint64_t const index, bool const success, std::string_view const data) -> void;

        virtual auto showSaveDialog(std::filesystem::path const& initialPath,
                                    std::string_view const filter) -> std::optional<std::filesystem::path> = 0;

      protected:
        std::unordered_map<std::string, bind_func_t> bindCallbacks;
        idle_func_t idleCallback;
    };
} // namespace libwebview