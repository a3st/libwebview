import platform
import ctypes
from ctypes import cdll

class AboveLib:
    BIND_FUNC_T = ctypes.CFUNCTYPE(None, ctypes.c_void_p, ctypes.c_uint64, ctypes.c_char_p)

    def __init__(self):
        match platform.system():
            case 'Windows':
                self.lib = cdll.LoadLibrary("AboveEdge.dll")
            case 'Android':
                self.lib = None
            case _:
                raise RuntimeError("Your system is not supported")
        
        self.lib.above_create_app.argtypes = [
            ctypes.c_char_p, 
            ctypes.c_char_p, 
            ctypes.c_uint32, ctypes.c_uint32, 
            ctypes.c_bool,
            ctypes.c_bool
        ]

        self.lib.above_create_app.restype = ctypes.c_void_p

        self.lib.above_delete_app.argtypes = [ ctypes.c_void_p ]

        self.lib.above_run_app.argtypes = [ ctypes.c_void_p, ctypes.c_char_p ]

        self.lib.above_quit_app.argtypes = [ ctypes.c_void_p ]

        self.lib.above_set_max_size_app.argtypes = [ ctypes.c_void_p, ctypes.c_uint32, ctypes.c_uint32 ]

        self.lib.above_set_min_size_app.argtypes = [ ctypes.c_void_p, ctypes.c_uint32, ctypes.c_uint32 ]

        self.lib.above_bind.argtypes = [
            ctypes.c_void_p,
            ctypes.c_char_p, 
            AboveLib.BIND_FUNC_T,
            ctypes.c_void_p
        ]

        self.lib.above_result.argtypes = [
            ctypes.c_void_p,
            ctypes.c_uint64,
            ctypes.c_bool,
            ctypes.c_char_p
        ]

        self.lib.above_emit.argtypes = [
            ctypes.c_void_p,
            ctypes.c_char_p,
            ctypes.c_char_p
        ]

        self.above_create_app = self.lib.above_create_app
        self.above_delete_app = self.lib.above_delete_app
        self.above_run_app = self.lib.above_run_app
        self.above_quit_app = self.lib.above_quit_app
        self.above_set_max_size_app = self.lib.above_set_max_size_app
        self.above_set_min_size_app = self.lib.above_set_min_size_app
        self.above_bind = self.lib.above_bind
        self.above_result = self.lib.above_result
        self.above_emit = self.lib.above_emit