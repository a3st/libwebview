#include "precompiled.h"
#include "webview.hpp"

auto main(int32_t argc, char** argv) -> int32_t
{
    libwebview::App app("ionengine", "Shader Graph", 800, 600, false, true);

    app.bind<std::string const&, uint32_t const>("test", [](std::string const& arg1, uint32_t const arg2) {
        std::cout << 123 << std::endl;
    });

    app.run("http://google.com");
    return 0;
}