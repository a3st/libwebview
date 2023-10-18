import platform
import ctypes
from ctypes import cdll

class WebUILib:
    BIND_FUNC_T = ctypes.CFUNCTYPE(None, ctypes.c_void_p, ctypes.c_uint64, ctypes.c_char_p)

    def __init__(self):
        match platform.system():
            case 'Windows':
                self.lib = cdll.LoadLibrary("WebUIEdge.dll")
            case 'Android':
                self.lib = cdll.LoadLibrary("WebUICEF.so")
            case _:
                raise RuntimeError("Your system is not supported")
        
        self.lib.create_web_ui.argtypes = [
            ctypes.c_char_p, 
            ctypes.c_char_p, 
            ctypes.c_uint32, ctypes.c_uint32, 
            ctypes.c_bool,
            ctypes.c_bool
        ]

        self.lib.create_web_ui.restype = ctypes.c_void_p

        self.lib.delete_web_ui.argtypes = [ ctypes.c_void_p ]

        self.lib.web_ui_set_max_size.argtypes = [ ctypes.c_void_p, ctypes.c_uint32, ctypes.c_uint32 ]

        self.lib.web_ui_set_min_size.argtypes = [ ctypes.c_void_p, ctypes.c_uint32, ctypes.c_uint32 ]

        self.lib.web_ui_run.argtypes = [ ctypes.c_void_p, ctypes.c_char_p ]

        self.lib.web_ui_bind.argtypes = [
            ctypes.c_void_p,
            ctypes.c_char_p, 
            WebUILib.BIND_FUNC_T,
            ctypes.c_void_p
        ]

        self.lib.web_ui_result.argtypes = [
            ctypes.c_void_p,
            ctypes.c_uint64,
            ctypes.c_bool,
            ctypes.c_char_p
        ]

        self.lib.web_ui_quit.argtypes = [ ctypes.c_void_p ]

        self.lib.web_ui_execute_js.argtypes = [ ctypes.c_void_p, ctypes.c_char_p ]

        self.create_web_ui = self.lib.create_web_ui
        self.delete_web_ui = self.lib.delete_web_ui
        self.web_ui_set_max_size = self.lib.web_ui_set_max_size
        self.web_ui_set_min_size = self.lib.web_ui_set_min_size
        self.web_ui_run = self.lib.web_ui_run
        self.web_ui_bind = self.lib.web_ui_bind
        self.web_ui_result = self.lib.web_ui_result
        self.web_ui_quit = self.lib.web_ui_quit
        self.web_ui_execute_js = self.lib.web_ui_execute_js
