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

        // https://github.com/aminroosta/sqlite_modern_cpp/blob/master/hdr/sqlite_modern_cpp/utility/function_traits.h
        template <typename>
        struct function_traits;

        template <typename Function>
        struct function_traits : public function_traits<decltype(&Function::operator())>
        {
        };

        template <typename ClassType, typename ReturnType, typename... Arguments>
        struct function_traits<ReturnType (ClassType::*)(Arguments...) const>
        {
            typedef ReturnType result_type;

            typedef std::tuple<Arguments...> arguments;

            template <std::size_t Index>
            using argument = typename std::tuple_element<Index, std::tuple<Arguments...>>::type;

            static const std::size_t arity = sizeof...(Arguments);
        };
    } // namespace internal

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

        template <typename Func>
        auto bind(std::string_view const functionName, Func&& function) -> void
        {
            using func_ret_t = internal::function_traits<Func>::result_type;
            using func_arguments = internal::function_traits<Func>::arguments;

            platform->bind(functionName, [&, function](uint64_t const index, std::string_view const data) {
                simdjson::ondemand::parser parser;
                auto document = parser.iterate(data, data.size() + simdjson::SIMDJSON_PADDING);

                auto invoke_helper = [&, function]<size_t... I>(
                                         simdjson::fallback::ondemand::document_stream::iterator::value_type& document,
                                         std::index_sequence<I...>) {
                    constexpr auto numArgs = sizeof...(I);
                    std::array<std::string, numArgs> arguments;

                    size_t i = 0;
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
                                arguments[i] = std::to_string(value);
                                break;
                            }
                            case simdjson::ondemand::json_type::boolean: {
                                bool value;
                                error = argument.get_bool().get(value);
                                if (error != simdjson::SUCCESS)
                                {
                                    throw std::runtime_error("Failed to get value from received message");
                                }
                                arguments[i] = value ? "1" : "0";
                                break;
                            }
                            case simdjson::ondemand::json_type::null: {
                                arguments[i] = "";
                                break;
                            }
                            case simdjson::ondemand::json_type::object: {
                                simdjson::fallback::ondemand::object value;
                                error = argument.get_object().get(value);
                                if (error != simdjson::SUCCESS)
                                {
                                    throw std::runtime_error("Failed to get value from received message");
                                }
                                arguments[i] = value.raw_json().value();
                                break;
                            }
                            default: {
                                std::string_view value;
                                error = argument.get_string().get(value);
                                if (error != simdjson::SUCCESS)
                                {
                                    throw std::runtime_error("Failed to get value from received message");
                                }
                                arguments[i] = value;
                                break;
                            }
                        }

                        ++i;
                    }

                    if constexpr (std::is_integral_v<func_ret_t> || std::is_floating_point_v<func_ret_t>)
                    {
                        auto result =
                            function(internal::ConvertArray<std::tuple_element_t<I, func_arguments>, I, numArgs>()(
                                arguments)...);
                        platform->result(index, true, std::to_string(result));
                    }
                    else if constexpr (std::is_same_v<func_ret_t, std::basic_string<char, std::char_traits<char>,
                                                                                    std::allocator<char>>>)
                    {
                        auto result =
                            function(internal::ConvertArray<std::tuple_element_t<I, func_arguments>, I, numArgs>()(
                                arguments)...);
                        if (result.front() == '{' && result.back() == '}')
                        {
                            platform->result(index, true, result);
                        }
                        else
                        {
                            platform->result(index, true, "\"" + result + "\"");
                        }
                    }
                    else if constexpr (std::is_void_v<func_ret_t>)
                    {
                        function(internal::ConvertArray<std::tuple_element_t<I, func_arguments>, I, numArgs>()(
                            arguments)...);
                        platform->result(index, true, "");
                    }
                    else
                    {
                        static_assert(true, "Invalid return type");
                    }
                };

                if constexpr (internal::function_traits<Func>::arity != 0)
                {
                    invoke_helper(document, std::make_index_sequence<internal::function_traits<Func>::arity>());
                }
                else
                {
                    if constexpr (std::is_integral_v<func_ret_t> || std::is_floating_point_v<func_ret_t>)
                    {
                        auto result = function();
                        platform->result(index, true, std::to_string(result));
                    }
                    else if constexpr (std::is_same_v<func_ret_t, std::basic_string<char, std::char_traits<char>,
                                                                                    std::allocator<char>>>)
                    {
                        auto result = function();
                        if (result.front() == '{' && result.back() == '}')
                        {
                            platform->result(index, true, result);
                        }
                        else
                        {
                            platform->result(index, true, "\"" + result + "\"");
                        }
                    }
                    else if constexpr (std::is_void_v<func_ret_t>)
                    {
                        function();
                        platform->result(index, true, "");
                    }
                    else
                    {
                        static_assert(true, "Invalid return type");
                    }
                }
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

        auto showSaveDialog(std::filesystem::path const& initialPath,
                            std::string_view const filter) -> std::optional<std::filesystem::path>
        {
            return platform->showSaveDialog(initialPath, filter);
        }

      private:
        std::unique_ptr<Platform> platform;
    };
} // namespace libwebview