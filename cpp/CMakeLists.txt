cmake_minimum_required(VERSION 3.2.4)
project(WebUI VERSION 0.1.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

include_directories(
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/include"
)

if(WIN32)

add_library(WebUIEdge SHARED
    src/thread_queue.cpp
    src/string_utils.cpp
    src/platform/webui_edge.cpp
    src/webui.cpp
)

target_include_directories(WebUIEdge PRIVATE
    "${PROJECT_SOURCE_DIR}/thirdparty/json/include"
    "${PROJECT_SOURCE_DIR}/thirdparty/webview2/include"
)

target_link_directories(WebUIEdge PRIVATE
"${PROJECT_SOURCE_DIR}/thirdparty/webview2/lib/x64"
)

target_link_libraries(WebUIEdge
    dwmapi.lib
    WebView2LoaderStatic.lib
)

target_compile_definitions(WebUIEdge PUBLIC
    WEBUI_EDGE
)

target_precompile_headers(WebUIEdge PUBLIC "include/precompiled.h")

endif()

if(UNIX AND NOT APPLE)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)
pkg_check_modules(GTK REQUIRED webkitgtk-6.0)

add_library(WebUIWebKit SHARED
    src/platform/webui_webkit.cpp
    src/thread_queue.cpp
    src/webui.cpp
)

target_include_directories(WebUIWebKit PRIVATE
    "${PROJECT_SOURCE_DIR}/thirdparty/json/include"
    "${GTK_INCLUDE_DIRS}"
    "${WEBKITGTK_INCLUDE_DIRS}"
)

target_link_directories(WebUIWebKit PRIVATE
    "${GTK_LIBRARY_DIRS}"
    "${WEBKITGTK_LIBRARY_DIRS}"
)

target_link_libraries(WebUIWebKit
    "${GTK_LIBRARIES}"
    "${WEBKITGTK_LIBRARIES}"
)

target_compile_definitions(WebUIWebKit PUBLIC
    WEBUI_WEBKIT
)

set_target_properties(WebUIWebKit PROPERTIES PREFIX "")

target_precompile_headers(WebUIWebKit PUBLIC "include/precompiled.h")

endif()