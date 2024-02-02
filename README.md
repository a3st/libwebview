![splash](https://github.com/a3st/libwebview/raw/main/splash-main.png)

## Features

* Rapid development of desktop applications using Web technologies
* Minimum application weight due to the use of the WebView system component
* A very simple library with a simple C interface

## Requirements

* Windows
    * Installed WebView Edge component (Default on Windows 11)
    * Python 3.10+

## Install

```bash
pip install libwebview
```

## Example

```python
from libwebview import App

app = App(
    app_name="TestApp",
    title="Test App", 
    size=(800, 600), 
    resizeable=True)
app.set_max_size((0, 0))
app.set_min_size((500, 400))

@app.route
def window_close():
    app.quit()

app.run("resources/index.html")
```

## Wiki [Goto](https://github.com/a3st/libwebview/wiki)

## Roadmap

- [x] Windows implementation (WebView Edge)
- [ ] Linux implementation (WebKit)
- [ ] Android implementation (Android WebView)
- [ ] Customize label options menu

## License

Check LICENSE for additional information.