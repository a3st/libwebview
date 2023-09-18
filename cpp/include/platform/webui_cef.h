#pragma once

#include <gtk/gtk.h>
#include "thread_queue.h"

using bind_func_t = std::function<void(uint64_t const, std::string_view const)>;

class WebUICEF {
public:

    WebUICEF(
        std::string_view const title, 
        std::tuple<uint32_t, uint32_t> const size, 
        bool const resizeable,
        std::tuple<uint32_t, uint32_t> const min_size,
        std::tuple<uint32_t, uint32_t> const max_size,
        bool const is_debug
    );

    ~WebUICEF();

    auto run(std::string_view const index_file) -> void;

    auto bind(std::string_view const func_name, bind_func_t&& callback) -> void;

    auto execute_js(std::string_view const js) -> void;

    auto result(uint64_t const index, bool const success, std::string_view const data) -> void;

    auto quit() -> void;

private:
    GtkWindow* window;

    bool running;

    std::tuple<uint32_t, uint32_t> min_window_size;
    std::tuple<uint32_t, uint32_t> max_window_size;
    std::map<std::string, bind_func_t> js_callbacks;
};