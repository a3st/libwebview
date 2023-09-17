from webui.core import Application

app = Application(
    title="WebUI Template", 
    size=(800, 600), 
    resizeable=True, 
    min_size=(300, 300), 
    max_size=(900, 700), 
    backend='edge'
)


@app.on
def window_close(arg1, arg2, arg3, arg4, arg5, arg6):
    for i in range(0, 100000000):
        result = i * 1000
    print("ГЦ")

app.run(index_path="src/index.html")