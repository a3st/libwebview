import json
import os
from .wrapper import WebUILib

lib = WebUILib()

class App:
    def __init__(
        self,
        app_name: str,
        title: str, 
        size: tuple[int, int],
        resizeable: bool = False,
        is_debug: bool = True
    ):
        self.js_callbacks = []

        width, height = size

        self.web_ui = lib.create_web_ui(
            app_name.encode(),
            title.encode(),
            width, height,
            resizeable,
            is_debug
        )

    
    def __del__(self):
        lib.delete_web_ui(self.web_ui)


    def set_max_size(self, size: tuple[int, int]):
        width, height = size
        lib.web_ui_set_max_size(self.web_ui, width, height)

    
    def set_min_size(self, size: tuple[int, int]):
        width, height = size
        lib.web_ui_set_min_size(self.web_ui, width, height)


    def quit(self):
        lib.web_ui_quit(self.web_ui)


    def on(self, func):
        def wrapper(ctx, index, args):
            data = json.loads(args)
            try:
                if len(data) == 0:
                    ret = func()
                else:
                    ret = func(*data[0])
                if ret is not None:
                    data = json.dumps(ret)
                    lib.web_ui_result(self.web_ui, index, True, data.encode())
                else:
                    lib.web_ui_result(self.web_ui, index, True, "{}".encode())
            except Exception as e:
                data = json.dumps({ "error" : str(e) })
                lib.web_ui_result(self.web_ui, index, False, data.encode())

        self.js_callbacks.append(WebUILib.BIND_FUNC_T(lambda ctx, index, args: wrapper(ctx, index, args)))
        
        lib.web_ui_bind(
            self.web_ui,
            func.__name__.encode(),
            self.js_callbacks[-1],
            None
        )
        return wrapper


    def run(self, file_path: str):
        lib.web_ui_run(self.web_ui, ("file:///" + os.getcwd() + "/" + file_path).encode())


    def execute_js(self, js: str):
        lib.web_ui_execute_js(self.web_ui, js.encode())
