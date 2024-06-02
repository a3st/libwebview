// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

#include "platform.hpp"
#include <simdjson.h>

namespace libwebview
{
    namespace internal
    {
        template <typename Type, size_t Index, size_t Size>
        struct ConvertArray
        {
            using type = Type;

            auto operator()(std::array<std::string, Size>& array) -> type;
        };

        template <size_t Index, size_t Size>
        struct ConvertArray<std::string, Index, Size>
        {
            using type = std::string;

            auto operator()(std::array<std::string, Size>& array) -> type
            {
                return array[Index];
            }
        };

        template <size_t Index, size_t Size>
        struct ConvertArray<bool, Index, Size>
        {
            using type = bool;

            auto operator()(std::array<std::string, Size>& array) -> type
            {
                return std::stoi(array[Index]);
            }
        };

        template <size_t Index, size_t Size>
        struct ConvertArray<uint32_t, Index, Size>
        {
            using type = uint32_t;

            auto operator()(std::array<std::string, Size>& array) -> type
            {
                return std::stoi(array[Index]);
            }
        };
    } // namespace internal

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
            platform = Platform::createInstance(appName, title, width, height, resizeable, debugMode);
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
            platform->bind(functionName, [function](uint64_t const index, std::string_view const data) {
                simdjson::ondemand::parser parser;
                auto document = parser.iterate(data, data.size() + simdjson::SIMDJSON_PADDING);

                auto invoke_helper = [function]<size_t... I>(
                                         simdjson::fallback::ondemand::document_stream::iterator::value_type& document,
                                         std::index_sequence<I...>) {
                    constexpr auto numArgs = sizeof...(I);
                    std::array<std::string, numArgs> arguments;

                    size_t index = 0;
                    for (auto argument : document.get_array())
                    {
                        simdjson::fallback::ondemand::json_type valueType;

                        auto error = argument.type().get(valueType);
                        if (error != simdjson::SUCCESS)
                        {
                            throw std::runtime_error("Failed to get value from received message");
                        }

                        switch (valueType)
                        {
                            case simdjson::ondemand::json_type::number: {
                                int64_t value;
                                error = argument.get_int64().get(value);
                                if (error != simdjson::SUCCESS)
                                {
                                    throw std::runtime_error("Failed to get value from received message");
                                }
                                arguments[index] = std::to_string(value);
                                break;
                            }
                            case simdjson::ondemand::json_type::boolean: {
                                bool value;
                                error = argument.get_bool().get(value);
                                if (error != simdjson::SUCCESS)
                                {
                                    throw std::runtime_error("Failed to get value from received message");
                                }
                                arguments[index] = value ? "1" : "0";
                                break;
                            }
                            default: {
                                std::string_view value;
                                error = argument.get_string().get(value);
                                if (error != simdjson::SUCCESS)
                                {
                                    throw std::runtime_error("Failed to get value from received message");
                                }
                                arguments[index] = value;
                                break;
                            }
                        }

                        ++index;
                    }

                    function(EventArgs{.index = index}, internal::ConvertArray<Args, I, numArgs>()(arguments)...);
                };

                invoke_helper(document, std::index_sequence_for<Args...>());
            });
        }

        template <>
        auto bind(std::string_view const functionName, std::function<void(EventArgs const&)>&& function) -> void
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

        auto setIdle(std::function<void()>&& function) -> void
        {
            platform->setIdle(std::move(function));
        }

      private:
        std::unique_ptr<Platform> platform;
    };
} // namespace libwebview