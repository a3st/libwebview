cmake_minimum_required(VERSION 3.2.4)
project(ElBot VERSION 0.1.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

include_directories(
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/include"
)

add_library(WebUIEdge SHARED
    src/platform/webui_edge.cpp
    src/webui.cpp
)

target_include_directories(WebUIEdge PRIVATE
    "${PROJECT_SOURCE_DIR}/thirdparty/webview2/include"
)

target_link_directories(WebUIEdge PRIVATE
"${PROJECT_SOURCE_DIR}/thirdparty/webview2/lib/x64"
)

target_link_libraries(WebUIEdge
    dwmapi.lib
    WebView2LoaderStatic.lib
)

target_compile_definitions(WebUIEdge PRIVATE
    WEBUI_EDGE
)

target_precompile_headers(WebUIEdge PUBLIC "include/precompiled.h")