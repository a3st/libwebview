#pragma once

#include <gtk/gtk.h>
#include <gdk/gdkx.h>
#include <cef_app.h>
#include <cef_client.h>
#include <cef_browser.h>
#include "thread_queue.h"


class WebUIClient :
    public CefClient,
    public CefLifeSpanHandler,
    public CefLoadHandler
{
public:
    WebUIClient()
    {
    }

    virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler()
    {
        return this;
    }

    virtual CefRefPtr<CefLoadHandler> GetLoadHandler()
    {
        return this;
    }

    // CefLifeSpanHandler methods.
    void OnAfterCreated(CefRefPtr<CefBrowser> browser)
    {
        // Must be executed on the UI thread.

    }

    bool DoClose(CefRefPtr<CefBrowser> browser)
    {
        // Must be executed on the UI thread.
        
        return false;
    }

    void OnBeforeClose(CefRefPtr<CefBrowser> browser)
    {
    }

    void OnLoadEnd(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, int httpStatusCode)
    {

    }

    bool OnLoadError(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefLoadHandler::ErrorCode errorCode, const CefString & failedUrl, CefString & errorText)
    {
        return false;
    }

    void OnLoadingStateChange(CefRefPtr<CefBrowser> browser, bool isLoading, bool canGoBack, bool canGoForward)
    {
      
    }

    void OnLoadStart(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame)
    {
     
    }

    bool closeAllowed() const
    {
        return true;
    }

    bool isLoaded() const
    {
        return true;
    }

private:

    IMPLEMENT_REFCOUNTING(WebUIClient);
};


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

    CefRefPtr<WebUIClient> client;
    CefRefPtr<CefBrowser> browser;

    bool running;

    std::tuple<uint32_t, uint32_t> min_window_size;
    std::tuple<uint32_t, uint32_t> max_window_size;
    std::map<std::string, bind_func_t> js_callbacks;
};