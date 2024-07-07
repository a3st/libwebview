# Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

cmake_minimum_required(VERSION 3.25.3)
project(libwebview VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 11)

include(FetchContent)

FetchContent_Declare(simdjson
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/thirdparty/simdjson
    BINARY_DIR ${CMAKE_BINARY_DIR}/thirdparty/simdjson)

FetchContent_Declare(concurrencpp
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/thirdparty/concurrencpp
    BINARY_DIR ${CMAKE_BINARY_DIR}/thirdparty/concurrencpp)

FetchContent_MakeAvailable(simdjson concurrencpp)

if(WIN32)
add_library(libwebview_edge SHARED
    src/platform.cpp
    src/platform/edge.cpp
    src/webview.cpp)

target_include_directories(libwebview_edge PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/thirdparty/webview2/include)

target_link_directories(libwebview_edge PUBLIC
    ${PROJECT_SOURCE_DIR}/thirdparty/webview2/lib/x86_64)

target_link_libraries(libwebview_edge PUBLIC
    concurrencpp
    dwmapi.lib
    WebView2LoaderStatic.lib
    shcore.lib
    Comctl32.lib
    simdjson)

target_compile_definitions(libwebview_edge PUBLIC
    LIB_WEBVIEW_EDGE)

target_precompile_headers(libwebview_edge PUBLIC include/precompiled.h)

add_library(libwebview_edge_static STATIC
    src/platform.cpp
    src/platform/edge.cpp
    src/webview.cpp)

target_include_directories(libwebview_edge_static PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/thirdparty/webview2/include)

target_link_directories(libwebview_edge_static PUBLIC
    ${PROJECT_SOURCE_DIR}/thirdparty/webview2/lib/x86_64)

target_link_libraries(libwebview_edge_static PUBLIC
    concurrencpp
    dwmapi.lib
    WebView2LoaderStatic.lib
    shcore.lib
    Comctl32.lib
    simdjson)

target_compile_definitions(libwebview_edge_static PUBLIC
    LIB_WEBVIEW_EDGE)

target_precompile_headers(libwebview_edge_static PUBLIC include/precompiled.h)
endif()

add_executable(async_test tests/async_test.cpp)

target_link_libraries(async_test PRIVATE libwebview_edge_static)