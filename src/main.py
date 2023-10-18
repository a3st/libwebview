import os
os.add_dll_directory(os.path.join(os.getcwd(), "cpp", "build"))

from webui import App

app = App(
    app_name="test_app_python",
    title="WebUI Template", 
    size=(800, 600), 
    resizeable=True
)


@app.on
def window_close(arg1, arg2, arg3, arg4, arg5, arg6):
    print("Событие выполнено!")


app.run("resources/index.html")