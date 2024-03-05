from libwebview import App
from datetime import datetime

app = App(
    app_name="test_app_python", title="Test App", size=(800, 600), resizeable=False
)
app.set_max_size((800, 600))

def app_close():
    app.quit()

def get_message():
    app.emit("update_time", datetime.now().strftime("%d-%m-%Y"))
    return "Привет из libwebview!"

app.bind(app_close)
app.bind(get_message)

app.run("../resources/index.html")
