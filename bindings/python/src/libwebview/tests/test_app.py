from libwebview import App

app = App(
    app_name="test_app_python",
    title="WebUI Template", 
    size=(800, 600), 
    resizeable=True
)

app.set_max_size((0, 0))
app.set_min_size((500, 400))


@app.route
def window_close(arg1, arg2, arg3, arg4, arg5, arg6):
    app.emit('test_event', 2)
    print("Событие выполнено!")


app.run("../resources/index.html")