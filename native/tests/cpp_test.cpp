#include "precompiled.h"
#include "webview.hpp"

auto main(int32_t argc, char** argv) -> int32_t
{
    libwebview::App app("ionengine", "Shader Graph", 800, 600, false, true);

    app.bind<std::string, uint32_t, uint32_t>(
        "test", [](libwebview::EventArgs const& args, std::string arg1, uint32_t arg2, uint32_t arg3) {
            std::cout << std::format("{} {} {}", arg1, arg2, arg3) << std::endl;
        });

    app.run("file:///E:/GitHub/libwebview/native/build/index.html");
    return 0;
}