from webui import Application

app = Application(
    title="WebUI Template", 
    size=(800, 600), 
    resizeable=True, 
    min_size=(300, 300), 
    max_size=(900, 700), 
    backend='edge'
)


@app.on
def window_close():
    print("Привет мир!")


app.run(index_path="src/index.html")