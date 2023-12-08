### Features

* Rapid development of desktop applications using Web technologies
* Minimum application weight due to the use of the WebView system component
* A very simple library with a simple C interface

### Requirements

1. Windows
    * Installed WebView Edge component (Default on Windows 11)
    * Python 3.10+

### Example

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
def window_close(arg1, arg2, arg3, arg4, arg5, arg6):
    app.quit()

app.run("../resources/index.html")
```

### License

Check LICENSE for additional information.