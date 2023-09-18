import ctypes
from ctypes import cdll
import platform
import os
import json

class Application:
    def __init__(
        self, 
        title: str, 
        size: tuple[int, int],
        resizeable: bool = False,
        min_size: tuple[int, int] = (-1, -1),
        max_size: tuple[int, int] = (-1, -1),
        is_debug: bool = True
    ):
        match platform.system():
            case 'Windows':
                self.lib = cdll.LoadLibrary("cpp/build/WebUIEdge.dll")
            case 'Linux':
                self.lib = cdll.LoadLibrary("cpp/build/WebUICEF.so")
            case _:
                raise RuntimeError("Your system is not supported")

        self.lib.create_web_ui.argtypes = [
            ctypes.c_char_p, 
            ctypes.c_uint32, ctypes.c_uint32, 
            ctypes.c_bool, 
            ctypes.c_uint32, ctypes.c_uint32, 
            ctypes.c_uint32, ctypes.c_uint32, 
            ctypes.c_bool
        ]
        self.lib.create_web_ui.restype = ctypes.c_void_p

        self.lib.web_ui_run.argtypes = [ctypes.c_void_p, ctypes.c_char_p]

        self.BIND_FUNC = ctypes.CFUNCTYPE(None, ctypes.c_void_p, ctypes.c_uint64, ctypes.c_char_p)

        self.lib.web_ui_bind.argtypes = [
            ctypes.c_void_p,
            ctypes.c_char_p, 
            self.BIND_FUNC,
            ctypes.c_void_p
        ]

        self.lib.web_ui_result.argtypes = [
            ctypes.c_void_p,
            ctypes.c_uint64,
            ctypes.c_bool,
            ctypes.c_char_p
        ]

        self.lib.web_ui_quit.argtypes = [ ctypes.c_void_p ]

        self.lib.delete_web_ui.argtypes = [ ctypes.c_void_p ]

        width, height = size
        min_width, min_height = min_size
        max_width, max_height = max_size

        self.web_ui = self.lib.create_web_ui(
            title.encode(), 
            width, height, 
            resizeable, 
            min_width, min_height,
            max_width, max_height,
            is_debug
        )

        self.js_callbacks = []

    
    def __del__(self):
        self.lib.delete_web_ui(self.web_ui)


    def quit(self):
        self.lib.web_ui_quit(self.web_ui)


    def on(self, func):
        def wrapper(ctx, index, args):
            data = json.loads(args)
            try:
                ret = func(*data[0])
                if ret is not None:
                    data = json.dumps(ret)
                    self.lib.web_ui_result(self.web_ui, index, True, data.encode())
                else:
                    self.lib.web_ui_result(self.web_ui, index, True, "{}".encode())
            except Exception as e:
                data = json.dumps({ "error" : str(e) })
                self.lib.web_ui_result(self.web_ui, index, False, data.encode())

        self.js_callbacks.append(self.BIND_FUNC(lambda ctx, index, args: wrapper(ctx, index, args)))
        
        self.lib.web_ui_bind(
            self.web_ui,
            func.__name__.encode(),
            self.js_callbacks[-1],
            None
        )
        return wrapper


    def run(self, index_path: str):
        full_path = "file:///" + os.getcwd() + "/" + index_path
        self.lib.web_ui_run(self.web_ui, full_path.encode())

