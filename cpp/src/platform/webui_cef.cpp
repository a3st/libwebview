#include "precompiled.h"
#include "platform/webui_cef.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <cef_path_util.h>
#include <internal/cef_types.h>

WebUICEF::WebUICEF(
    std::string_view const title, 
    std::tuple<uint32_t, uint32_t> const size, 
    bool const resizeable,
    std::tuple<uint32_t, uint32_t> const min_size,
    std::tuple<uint32_t, uint32_t> const max_size, 
    bool const is_debug
) :
    min_window_size(min_size), max_window_size(max_size), running(false)
{
    std::cout << std::filesystem::current_path().string() + "/log.txt" << std::endl;
    CefString path;
    CefGetPath(PK_DIR_MODULE, path);
    std::cout << path.ToString() << std::endl;

    CefGetPath(PK_DIR_EXE, path);
    std::cout << path.ToString() << std::endl;
    {
        CefMainArgs args(0, NULL);
        CefSettings settings;
        CefString(&settings.log_file) = std::filesystem::current_path().string() + "/log.txt";
        settings.log_severity = cef_log_severity_t::LOGSEVERITY_WARNING;
        CefString(&settings.resources_dir_path) = std::filesystem::current_path().string() + "/cpp/build";
        CefString(&settings.framework_dir_path) = std::filesystem::current_path().string() + "/cpp/build";
        
        bool result = CefInitialize(args, settings, nullptr, nullptr);
    }

    gtk_init(0, NULL);

    window = GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));

    gtk_window_set_default_size(window, 800, 600);

    auto window_info = CefWindowInfo {};
    window_info.SetAsChild(
        gdk_x11_window_get_xid(gtk_widget_get_window(GTK_WIDGET(window))),
        CefRect {
            0, 0, 800, 600
        }
    );
    
    //client = new WebUIClient();


    //auto settings = CefBrowserSettings {};
    //browser = CefBrowserHost::CreateBrowserSync(window_info, client, CefString("src/index.html"), settings, nullptr);
}


WebUICEF::~WebUICEF() {
    gtk_widget_destroy(GTK_WIDGET(window));
}


auto WebUICEF::run(std::string_view const index_file) -> void {

    gtk_window_present(window);

    gtk_main();
    gtk_main_quit();
}


auto WebUICEF::bind(std::string_view const func_name, bind_func_t&& callback) -> void {
    if(js_callbacks.find(std::string(func_name)) != js_callbacks.end()) {
        throw std::runtime_error("Cannot to bind a function that already exists");
    }
    js_callbacks.insert({ std::string(func_name), std::move(callback) });
}


auto WebUICEF::execute_js(std::string_view const js) -> void {

}


auto WebUICEF::result(uint64_t const index, bool const success, std::string_view const data) -> void {

}


auto WebUICEF::quit() -> void {

}