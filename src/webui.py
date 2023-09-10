from ctypes import cdll
import ctypes
import platform

class Application:
    def __init__(self, title: str, width: int, height: int, backend: str='default'):
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

        self.lib.create_web_ui.argtypes = [ctypes.c_char_p, ctypes.c_uint32, ctypes.c_uint32]
        self.lib.create_web_ui.restype = ctypes.c_void_p

        self.lib.web_ui_run.argtypes = [ctypes.c_void_p]

        self.web_ui = self.lib.create_web_ui(title.encode(), 800, 600)

    
    def quit(self):
        pass


    def on(self, func):

        def wrapper():
            print(func.__name__)
            func()
        return wrapper


    def run(self):
        self.lib.web_ui_run(self.web_ui)

