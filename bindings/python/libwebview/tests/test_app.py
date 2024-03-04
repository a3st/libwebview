from libwebview import App
from datetime import datetime

app = App(
    app_name="test_app_python", title="Test App", size=(800, 600), resizeable=False
)
app.set_max_size((800, 600))


@app.route
def app_close():
    app.quit()


@app.route
def get_message():
    app.emit("update_time", datetime.now().strftime("%d-%m-%Y"))
    return "Привет из libwebview!"


app.run("resources/index.html")
