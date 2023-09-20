#include "precompiled.h"
#include "webui.h"

int main(int argc, char** argv) {
    CWebUI web_ui = create_web_ui("123", 800, 600, true, 100, 200, 1000, 400, true);

    web_ui_run(web_ui, "index.html");
    return 0;
}