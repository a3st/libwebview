# Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

cmake_minimum_required(VERSION 3.25.1)

project(libwebview VERSION 1.0.0 LANGUAGES C CXX)

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
add_library(libwebview_edge STATIC
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

add_executable(async_test tests/async_test.cpp)

target_link_libraries(async_test PRIVATE libwebview_edge)
endif()

if(UNIX)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)
pkg_check_modules(WEBKITGTK REQUIRED webkitgtk-6.0)
pkg_check_modules(LIBADWAITA REQUIRED libadwaita-1)

add_library(libwebview_webkit STATIC
    src/platform.cpp
    src/platform/webkit.cpp
    src/webview.cpp)

target_include_directories(libwebview_webkit PUBLIC
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/include
    ${WEBKITGTK_INCLUDE_DIRS}
    ${LIBADWAITA_INCLUDE_DIRS}
    ${GTK_INCLUDE_DIRS})

target_link_directories(libwebview_webkit PUBLIC
    ${WEBKITGTK_LIBRARY_DIRS}
    ${LIBADWAITA_LIBRARY_DIRS}
    ${GTK_LIBRARY_DIRS})

target_link_libraries(libwebview_webkit PUBLIC
    concurrencpp
    simdjson
    ${WEBKITGTK_LIBRARIES}
    ${LIBADWAITA_LIBRARIES}
    ${GTK_LIBRARIES})

target_compile_definitions(libwebview_webkit PUBLIC
    LIB_WEBVIEW_WEBKIT)

target_precompile_headers(libwebview_webkit PUBLIC include/precompiled.h)

add_executable(async_test tests/async_test.cpp)

target_link_libraries(async_test PRIVATE libwebview_webkit)
endif()