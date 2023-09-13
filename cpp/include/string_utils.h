#pragma once

namespace string_utils {

auto to_wstring(std::string_view const source) -> std::wstring;

auto to_string(std::wstring_view const source) -> std::string;

}