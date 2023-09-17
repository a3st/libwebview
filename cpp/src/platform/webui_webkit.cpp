#include "precompiled.h"
#include "platform/webui_webkit.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
#include "string_utils.h"


WebUIWebkit::WebUIWebkit(
    std::string_view const title, 
    std::tuple<uint32_t, uint32_t> const size, 
    bool const resizeable,
    std::tuple<uint32_t, uint32_t> const min_size,
    std::tuple<uint32_t, uint32_t> const max_size, 
    bool const is_debug
) :
    min_window_size(min_size), max_window_size(max_size) 
{
    
}


auto WebUIWebkit::run(std::string_view const index_file) -> void {

}


auto WebUIWebkit::bind(std::string_view const func_name, bind_func_t&& callback) -> void {
    if(js_callbacks.find(std::string(func_name)) != js_callbacks.end()) {
        throw std::runtime_error("Cannot to bind a function that already exists");
    }
    js_callbacks.insert({ std::string(func_name), std::move(callback) });
}


auto WebUIWebkit::execute_js(std::string_view const js) -> void {

}


auto WebUIWebkit::result(uint64_t const index, bool const success, std::string_view const data) -> void {

}


auto WebUIWebkit::quit() -> void {

}