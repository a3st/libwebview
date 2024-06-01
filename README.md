![splash](https://github.com/a3st/libwebview/raw/main/media/splash-main.png)

## Features

* Rapid development of desktop applications using Web technologies
* Minimum application weight due to the use of the WebView system component
* A very simple library with a simple C/C++ interface

## Requirements

* Windows
    * Installed WebView Edge component
    * Python 3.10+

## Install

```bash
pip install libwebview
```

## Python Example

```python
from libwebview import App

app = App(
    app_name="TestApp",
    title="Test App", 
    size=(800, 600), 
    resizeable=True)
app.set_max_size((0, 0))
app.set_min_size((500, 400))

def window_close():
    app.quit()

app.bind(window_close)

app.run("resources/index.html")
```

## C++ Example

```c++
#include <webview.hpp>

int32_t main(int32_t argc, char** argv) {
    try {
        libwebview::App app("TestApp", "Test App", 800, 600, true, true);
        app.run("resources/index.html");
    } catch(std::runtime_error e) {
        std::cerr << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
```

## Wiki [Goto](https://github.com/a3st/libwebview/wiki)

## Showcase

### [IONENGINE - Editor](https://github.com/a3st/IONENGINE)
![App](https://github.com/a3st/libwebview/raw/main/media/ionengine-editor.png)

## Roadmap

- [x] Windows implementation (WebView Edge)
- [ ] Linux implementation (WebKit)
- [ ] Android implementation (Android WebView)

## License

Check LICENSE for additional information