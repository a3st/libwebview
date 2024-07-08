// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "platform/webkit.hpp"
#include "injection.hpp"
#include "precompiled.h"
#include <simdjson.h>

namespace libwebview
{
    GtkWidget* parentWindowDialog = nullptr;
    GFile* selectedFile = nullptr;

    WebKit::WebKit(std::string_view const appName, std::string_view const title, uint32_t const width,
                   uint32_t const height, bool const resizeable, bool const debugMode)
        : appName(appName), semaphore(0), minSize{}, maxSize{}
    {
        gtk_init();

        window = GTK_WINDOW(gtk_window_new());
        gtk_window_set_title(window, std::string(title).c_str());
        gtk_window_set_default_size(window, width, height);
        gtk_window_set_resizable(window, resizeable);

        parentWindowDialog = GTK_WIDGET(window);

        /*
        g_signal_connect_after(
            window, "notify::default-width", G_CALLBACK(*[](GObject* object, GParamSpec* param, gpointer userData) {
                auto platformInstance = reinterpret_cast<WebKit*>(userData);
                int32_t width;
                int32_t height;

                gtk_window_get_default_size(platformInstance->window, &width, &height);
                if (platformInstance->minSize.width != 0)
                {
                    if (platformInstance->minSize.width > width)
                    {
                        gtk_window_set_default_size(platformInstance->window, platformInstance->minSize.width, height);
                    }
                }
            }),
            this);

        g_signal_connect_after(
            window, "notify::default-height", G_CALLBACK(*[](GObject* object, GParamSpec* param, gpointer userData) {
                auto platformInstance = reinterpret_cast<WebKit*>(userData);
                int32_t width;
                int32_t height;

                gtk_window_get_default_size(platformInstance->window, &width, &height);
                if (platformInstance->minSize.height != 0)
                {
                    if (platformInstance->minSize.height > height)
                    {
                        gtk_window_set_default_size(platformInstance->window, width, platformInstance->minSize.height);
                    }
                }
            }),
            this);
        */

        webview = WEBKIT_WEB_VIEW(webkit_web_view_new());
        gtk_window_set_child(window, GTK_WIDGET(webview));

        WebKitUserContentManager* manager = webkit_web_view_get_user_content_manager(webview);
        g_signal_connect(manager, "script-message-received::__global__",
                         G_CALLBACK(*[](WebKitUserContentManager* webview, JSCValue* value, gpointer userData) {
                             auto platformInstance = reinterpret_cast<WebKit*>(userData);

                             char* buffer = jsc_value_to_string(value);
                             std::string const jsonData = std::string(buffer);

                             simdjson::ondemand::parser parser;
                             auto document = parser.iterate(jsonData, jsonData.size() + simdjson::SIMDJSON_PADDING);

                             uint64_t index;
                             auto error = document["index"].get_uint64().get(index);
                             if (error != simdjson::error_code::SUCCESS)
                             {
                                 g_free(buffer);
                                 return;
                             }

                             std::string_view functionName;
                             error = document["func"].get_string().get(functionName);
                             if (error != simdjson::error_code::SUCCESS)
                             {
                                 g_free(buffer);
                                 return;
                             }

                             std::string_view argumentData;
                             error = document["args"].raw_json().get(argumentData);
                             if (error != simdjson::error_code::SUCCESS)
                             {
                                 g_free(buffer);
                                 return;
                             }

                             auto found = platformInstance->bindCallbacks.find(std::string(functionName));
                             if (found != platformInstance->bindCallbacks.end())
                             {
                                 found->second(index, argumentData);
                             }

                             g_free(buffer);
                         }),
                         this);

        webkit_user_content_manager_register_script_message_handler(manager, "__global__", nullptr);

        WebKitSettings* settings = webkit_web_view_get_settings(webview);
        webkit_settings_set_allow_file_access_from_file_urls(settings, true);

        if (debugMode)
        {
            webkit_settings_set_enable_developer_extras(settings, true);
        }
        else
        {
            g_signal_connect(webview, "context-menu",
                             G_CALLBACK(*[](GtkWidget* widget, gpointer userData) { return true; }), nullptr);
        }
    }

    auto WebKit::setWindowMaxSize(uint32_t const width, uint32_t const height) -> void
    {
        maxSize = {.width = width, .height = height};
    }

    auto WebKit::setWindowMinSize(uint32_t const width, uint32_t const height) -> void
    {
        minSize = {.width = width, .height = height};
    }

    auto WebKit::setWindowSize(uint32_t const width, uint32_t const height) -> void
    {
        gtk_window_set_default_size(window, width, height);
    }

    auto WebKit::run(std::string_view const urlPath) -> void
    {
        WebKitUserContentManager* manager = webkit_web_view_get_user_content_manager(webview);

        WebKitUserScript* loadScript = webkit_user_script_new(
            std::vformat(js::onLoadHTMLInjection, std::make_format_args("window.webkit.messageHandlers.__global__"))
                .c_str(),
            WEBKIT_USER_CONTENT_INJECT_TOP_FRAME, WEBKIT_USER_SCRIPT_INJECT_AT_DOCUMENT_START, nullptr, nullptr);

        webkit_user_content_manager_add_script(manager, loadScript);

        if (urlPath.starts_with("http://") || urlPath.starts_with("https://"))
        {
            webkit_web_view_load_uri(webview, std::string(urlPath).c_str());
        }
        else
        {
            std::filesystem::path const currentPath = std::filesystem::current_path();
            webkit_web_view_load_uri(webview, ("file:///" + (currentPath / urlPath).generic_string()).c_str());
        }

        bool running = true;

        g_signal_connect(window, "destroy", G_CALLBACK(*[](GtkWidget* widget, gpointer userData) {
                             auto running = reinterpret_cast<bool*>(userData);
                             (*running) = false;
                         }),
                         &running);

        gtk_window_present(GTK_WINDOW(window));

        while (running)
        {
            g_main_context_iteration(nullptr, false);
            if (idleCallback)
            {
                idleCallback();
            }
        }

        webkit_user_script_unref(loadScript);
    }

    auto WebKit::executeJavaScript(std::string_view const executeCode) -> void
    {
        webkit_web_view_evaluate_javascript(webview, std::string(executeCode).c_str(), -1, nullptr, nullptr, nullptr,
                                            nullptr, nullptr);
    }

    auto WebKit::quit() -> void
    {
        gtk_window_close(GTK_WINDOW(window));
    }

    auto WebKit::showSaveDialog(std::filesystem::path const& initialPath,
                                std::string_view const filter) -> std::optional<std::filesystem::path>
    {
        GtkFileDialog* dialog = GTK_FILE_DIALOG(gtk_file_dialog_new());

        gtk_file_dialog_save(dialog, window, nullptr,
                             (GAsyncReadyCallback)(*[](GtkFileDialog* dialog, GAsyncResult* result, gpointer userData) {
                                 auto platformInstance = reinterpret_cast<WebKit*>(userData);
                                 selectedFile = gtk_file_dialog_save_finish(dialog, result, nullptr);
                                 platformInstance->semaphore.release();
                             }),
                             this);

        while (!semaphore.try_acquire())
        {
            g_main_context_iteration(nullptr, false);
        }

        if (selectedFile)
        {
            std::filesystem::path const outPath = g_file_get_path(selectedFile);
            g_free(selectedFile);
            return outPath;
        }
        else
        {
            return std::nullopt;
        }
    }

    auto showMessageDialog(std::string_view const title, std::string_view const message,
                           MessageDialogType const messageType) -> void
    {
        AdwAlertDialog* dialog =
            ADW_ALERT_DIALOG(adw_alert_dialog_new(std::string(title).c_str(), std::string(message).c_str()));
        adw_alert_dialog_add_response(dialog, "ok", "OK");
        adw_alert_dialog_set_default_response(dialog, "ok");

        adw_dialog_present(ADW_DIALOG(dialog), parentWindowDialog);
    }
} // namespace libwebview