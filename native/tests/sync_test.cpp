#include "precompiled.h"
#include <webview.hpp>

int32_t main(int32_t argc, char** argv)
{
    libwebview::App app("org.libwebview.test", "testApp", 800, 600, true, true);
    app.setWindowMinSize(200, 200);

    app.bind("syncTest", [&]() -> int32_t {
        std::cout << "Hello world!" << std::endl;
        return 20;
    });

    app.run("index.html");
    return EXIT_SUCCESS;
}