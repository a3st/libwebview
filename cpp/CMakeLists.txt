cmake_minimum_required(VERSION 3.25.3)
project(LibWebView VERSION 1.0.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 11)

if(WIN32)

add_library(WebViewEdge SHARED
    "src/thread_queue.cpp"
    "src/platform/edge.cpp"
    "src/webview.cpp"
)

target_include_directories(WebViewEdge PRIVATE
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/thirdparty/json/include"
    "${PROJECT_SOURCE_DIR}/thirdparty/webview2/include"
)

target_link_directories(WebViewEdge PRIVATE
    "${PROJECT_SOURCE_DIR}/thirdparty/webview2/lib/x86_64"
)

target_link_libraries(WebViewEdge
    dwmapi.lib
    WebView2LoaderStatic.lib
    shcore.lib
)

target_compile_definitions(WebViewEdge PRIVATE
    LIB_WEBVIEW_EDGE
)

target_precompile_headers(WebViewEdge PRIVATE "include/precompiled.h")

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