from ctypes import cdll
import ctypes
import platform
import pathlib
import os

class Application:
    def __init__(
            self, 
            title: str, 
            size: tuple[int, int],
            resizeable: bool = False,
            min_size: tuple[int, int] = (-1, -1),
            max_size: tuple[int, int] = (-1, -1),
            is_debug: bool = True, 
            backend: str='default',
        ):
        match backend:
            case 'edge':
                self.lib = cdll.LoadLibrary("cpp/build/WebUIEdge.dll")
            case 'cef':
                self.lib = cdll.LoadLibrary("cpp/build/WebUICEF.dll")
            case 'webkit':
                self.lib = cdll.LoadLibrary("cpp/build/WebUIWebkit.dll")
            case 'default':
                #match platform.platform():
                #    case 'Windows':
                #        self.lib
                pass
            case _:
                pass

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

        self.BIND_FUNC = ctypes.CFUNCTYPE(ctypes.c_void_p, ctypes.c_void_p, ctypes.c_char_p)

        self.lib.web_ui_bind.argtypes = [
            ctypes.c_void_p, 
            ctypes.c_char_p, 
            self.BIND_FUNC,
            ctypes.c_void_p
        ]

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

        self.callbacks = []

    
    def quit(self):
        pass


    def on(self, func):
        def wrapper():
            print(func.__name__)
            func()

        self.callbacks.append(self.BIND_FUNC(lambda app, args: wrapper()))
        
        self.lib.web_ui_bind(
            self.web_ui,
            func.__name__.encode(),
            self.callbacks[0],
            None
        )
        return wrapper


    def run(self, index_path: str):
        full_path = "file:///" + os.getcwd() + "/" + index_path
        self.lib.web_ui_run(self.web_ui, full_path.encode())

