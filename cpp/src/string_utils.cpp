#include "precompiled.h"
#include "string_utils.h"
#define NOMINMAX
#include <windows.h>
#undef NOMINMAX

auto string_utils::to_wstring(std::string_view const source) -> std::wstring {
    int32_t length = ::MultiByteToWideChar(
        CP_UTF8, 
        0, 
        source.data(), 
        static_cast<int32_t>(source.size()),
        nullptr,
        0
    );

    std::wstring dest(length, '\0');

    ::MultiByteToWideChar(
        CP_UTF8, 
        0, 
        source.data(), 
        static_cast<int32_t>(source.size()),
        dest.data(),
        length
    );
    return dest;
}

auto string_utils::to_string(std::wstring_view const source) -> std::string {
    int32_t length = WideCharToMultiByte(
        CP_UTF8, 
        0, 
        source.data(), 
        static_cast<int32_t>(source.size()), 
        nullptr, 
        0, 
        nullptr, 
        nullptr
    );
    
    std::string dest(length, '\0');

    WideCharToMultiByte(
        CP_UTF8, 
        0, 
        source.data(), 
        static_cast<int32_t>(source.size()), 
        dest.data(), 
        static_cast<int32_t>(dest.size()), 
        nullptr, 
        nullptr
    );
    return dest;                                 
}