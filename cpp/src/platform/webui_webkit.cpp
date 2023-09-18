#include "precompiled.h"
#include "platform/webui_webkit.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;


WebUIWebKit::WebUIWebKit(
    std::string_view const title, 
    std::tuple<uint32_t, uint32_t> const size, 
    bool const resizeable,
    std::tuple<uint32_t, uint32_t> const min_size,
    std::tuple<uint32_t, uint32_t> const max_size, 
    bool const is_debug
) :
    min_window_size(min_size), max_window_size(max_size), running(false)
{
    gtk_init();

    window = gtk_window_new();
    gtk_window_set_title(GTK_WINDOW(window), std::string(title).c_str());
    gtk_window_set_default_size(GTK_WINDOW(window), std::get<0>(size), std::get<1>(size));

    g_signal_connect(window, "destroy", G_CALLBACK(+[](GtkWidget* sender, gpointer data) -> void { 
        auto window = reinterpret_cast<WebUIWebKit*>(data);
        window->running = false;
    }), this);

    webview = webkit_web_view_new();
    
    gtk_window_set_child(GTK_WINDOW(window), webview);
    gtk_window_present(GTK_WINDOW(window));
}


WebUIWebKit::~WebUIWebKit() {
    gtk_window_destroy(GTK_WINDOW(window));
}


auto WebUIWebKit::run(std::string_view const index_file) -> void {
    webkit_web_view_load_uri(WEBKIT_WEB_VIEW(webview), index_file.data());

    running = true;
    while(running) {
        while(g_main_context_pending(nullptr)) {
            g_main_context_iteration(nullptr, TRUE);
        }
    }
}


auto WebUIWebKit::bind(std::string_view const func_name, bind_func_t&& callback) -> void {
    if(js_callbacks.find(std::string(func_name)) != js_callbacks.end()) {
        throw std::runtime_error("Cannot to bind a function that already exists");
    }
    js_callbacks.insert({ std::string(func_name), std::move(callback) });
}


auto WebUIWebKit::execute_js(std::string_view const js) -> void {

}


auto WebUIWebKit::result(uint64_t const index, bool const success, std::string_view const data) -> void {

}


auto WebUIWebKit::quit() -> void {

}