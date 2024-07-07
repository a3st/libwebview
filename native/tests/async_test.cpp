#include "precompiled.h"
#include <webview.hpp>

int32_t main(int32_t argc, char** argv)
{
    libwebview::App app("testAppAsync", "testApp", 800, 600, true, true);

    app.bind("syncTest", []() -> int32_t {
        std::cout << "Sync hello world!" << std::endl;
        return 20;
    });

    app.bind("asyncTest", []() -> concurrencpp::result<std::string> {
        // Emulate high load work
        std::this_thread::sleep_for(std::chrono::seconds(5));
        std::cout << "Async hello world!" << std::endl;
        co_return "Hello world!";
    });

    app.run("index.html");
    return EXIT_SUCCESS;
}