import json
import os
from .wrapper import AboveLib

lib = AboveLib()

class App:
    def __init__(
        self,
        app_name: str,
        title: str, 
        size: tuple[int, int],
        resizeable: bool = False,
        is_debug: bool = True
    ):
        self.callbacks = []

        width, height = size

        self.instance = lib.above_create_app(
            app_name.encode(),
            title.encode(),
            width, height,
            resizeable,
            is_debug
        )

    
    def __del__(self):
        lib.above_delete_app(self.instance)


    def set_max_size(self, size: tuple[int, int]):
        width, height = size
        lib.above_set_max_size_app(self.instance, width, height)

    
    def set_min_size(self, size: tuple[int, int]):
        width, height = size
        lib.above_set_min_size_app(self.instance, width, height)


    def quit(self):
        lib.above_quit_app(self.instance)


    def emit(self, event, args):
        data = json.dumps(args)
        lib.above_emit(self.instance, event.encode(), data.encode())


    def route(self, func):
        def wrapper(ctx, index, args):
            data = json.loads(args)

            try:
                if len(data) == 0:
                    ret = func()
                else:
                    ret = func(*data[0])
                if ret is not None:
                    data = json.dumps(ret)
                    lib.above_result(self.instance, index, True, data.encode())
                else:
                    lib.above_result(self.instance, index, True, "{}".encode())

            except Exception as e:
                data = json.dumps({ "error" : str(e) })
                lib.above_result(self.instance, index, False, data.encode())

        self.callbacks.append(AboveLib.BIND_FUNC_T(lambda ctx, index, args: wrapper(ctx, index, args)))
        
        lib.above_bind(
            self.instance,
            func.__name__.encode(),
            self.callbacks[-1],
            None
        )
        return wrapper


    def run(self, file_path: str):
        lib.above_run_app(self.instance, ("file:///" + os.getcwd() + "/" + file_path).encode())