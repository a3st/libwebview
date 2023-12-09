from libwebview import App

app = App(
    app_name="test_app_python",
    title="Test App", 
    size=(800, 600), 
    resizeable=True
)

app.set_max_size((0, 0))
app.set_min_size((500, 400))


@app.route
def window_close():
    app.quit()


app.run("resources/index.html")