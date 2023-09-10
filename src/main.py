from webui import Application

app = Application(title="WebUI Template", width=800, height=600, backend='edge')

@app.on
def window_close():
    app.quit()


app.run()

# window_close()