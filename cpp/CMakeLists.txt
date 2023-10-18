cmake_minimum_required(VERSION 3.25.3)
project(WebUI VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

if(WIN32)

add_library(WebUIEdge SHARED
    "src/thread_queue.cpp"
    "src/platform/webui_edge.cpp"
    "src/webui.cpp"
)

target_include_directories(WebUIEdge PRIVATE
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/thirdparty/json/include"
    "${PROJECT_SOURCE_DIR}/thirdparty/webview2/include"
)

target_link_directories(WebUIEdge PRIVATE
    "${PROJECT_SOURCE_DIR}/thirdparty/webview2/lib/x86_64"
)

target_link_libraries(WebUIEdge
    dwmapi.lib
    WebView2LoaderStatic.lib
)

target_compile_definitions(WebUIEdge PRIVATE
    WEBUI_EDGE
)

target_precompile_headers(WebUIEdge PRIVATE "include/precompiled.h")

endif()

if(UNIX AND NOT APPLE)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)

add_library(WebUICEF SHARED
    src/platform/webui_cef.cpp
    src/thread_queue.cpp
    src/webui.cpp
)

target_include_directories(WebUICEF PRIVATE
    "${PROJECT_SOURCE_DIR}/thirdparty/json/include"
    "${PROJECT_SOURCE_DIR}/thirdparty/cef/include"
    "${PROJECT_SOURCE_DIR}/thirdparty/cef"
    ${GTK_INCLUDE_DIRS}
)

target_link_directories(WebUICEF PRIVATE
    ${GTK_LIBRARY_DIRS}
    "${PROJECT_SOURCE_DIR}/thirdparty/cef/lib/x64"
)

target_link_libraries(WebUICEF
    ${GTK_LIBRARIES}
    libcef.so
    libcef_dll_wrapper.a
)

target_compile_definitions(WebUICEF PRIVATE
    WEBUI_CEF
)

set_target_properties(WebUICEF PROPERTIES PREFIX "")

target_precompile_headers(WebUICEF PRIVATE "include/precompiled.h")

endif()