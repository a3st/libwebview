#include "precompiled.h"
#include "above.h"

C_Above above_create_app(
    char const* app_name,
    char const* title, 
    uint32_t const width, 
    uint32_t const height, 
    bool const resizeable,
    bool const is_debug
) {
    try {
        auto web_ui = new AbovePlatform(app_name, title, { width, height }, resizeable, is_debug);
        return web_ui;
    } catch(std::runtime_error e) {
        return nullptr;
    }
}

void above_delete_app(C_Above instance) {
    delete instance;
}

void above_run_app(C_Above instance, char const* file_path) {
    reinterpret_cast<AbovePlatform*>(instance)->run(file_path);
}

void above_quit_app(C_Above instance) {
    reinterpret_cast<AbovePlatform*>(instance)->quit();
}

void above_set_max_size_app(C_Above instance, uint32_t const width, uint32_t const height) {
    reinterpret_cast<AbovePlatform*>(instance)->set_max_size({ width, height });
}

void above_set_min_size_app(C_Above instance, uint32_t const width, uint32_t const height) {
    reinterpret_cast<AbovePlatform*>(instance)->set_min_size({ width, height });
}

void above_set_size_app(C_Above instance, uint32_t const width, uint32_t const height) {
    reinterpret_cast<AbovePlatform*>(instance)->set_size({ width, height });
}

void above_bind(C_Above instance, char const* func_name, void(*callback)(void*, uint64_t, char const*), void* context) {
    reinterpret_cast<AbovePlatform*>(instance)->bind(func_name, [callback, context](uint64_t const index, std::string_view const data) { callback(context, index, data.data()); });
}

void above_result(C_Above instance, uint64_t index, bool success, char const* data) {
    reinterpret_cast<AbovePlatform*>(instance)->result(index, success, data);
}

void above_emit(C_Above instance, char const* event, char const* data) {
    reinterpret_cast<AbovePlatform*>(instance)->emit(event, data);
}