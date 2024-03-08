import platform
import ctypes
from ctypes import cdll
import os


class WebViewLib:
    BIND_FUNC_T = ctypes.CFUNCTYPE(
        None, ctypes.c_void_p, ctypes.c_uint64, ctypes.c_char_p
    )

    INVOKE_FUNC_T = ctypes.CFUNCTYPE(None, ctypes.c_void_p)

    def __init__(self):
        LIB_WEBVIEW_DIR = os.path.dirname(__file__)

        match platform.system():
            case "Windows":
                match platform.architecture()[0]:
                    case "64bit":
                        LIB_PATH = os.path.join(LIB_WEBVIEW_DIR, "lib", "x86_64")
                    case _:
                        raise RuntimeError("Your system is not supported")

                self.lib = cdll.LoadLibrary(
                    os.path.join(LIB_PATH, "libwebview_edge.dll")
                )
            case "Android":
                self.lib = None
            case _:
                raise RuntimeError("Your system is not supported")

        self.lib.webview_create_app.argtypes = [
            ctypes.c_char_p,
            ctypes.c_char_p,
            ctypes.c_uint32,
            ctypes.c_uint32,
            ctypes.c_bool,
            ctypes.c_bool,
        ]

        self.lib.webview_create_app.restype = ctypes.c_void_p

        self.lib.webview_delete_app.argtypes = [ctypes.c_void_p]

        self.lib.webview_run_app.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
        self.lib.webview_run_app.restype = ctypes.c_bool

        self.lib.webview_quit_app.argtypes = [ctypes.c_void_p]

        self.lib.webview_set_max_size_app.argtypes = [
            ctypes.c_void_p,
            ctypes.c_uint32,
            ctypes.c_uint32,
        ]

        self.lib.webview_set_min_size_app.argtypes = [
            ctypes.c_void_p,
            ctypes.c_uint32,
            ctypes.c_uint32,
        ]

        self.lib.webview_set_size_app.argtypes = [
            ctypes.c_void_p,
            ctypes.c_uint32,
            ctypes.c_uint32,
        ]

        self.lib.webview_bind.argtypes = [
            ctypes.c_void_p,
            ctypes.c_char_p,
            WebViewLib.BIND_FUNC_T,
            ctypes.c_void_p,
        ]
        self.lib.webview_bind.restype = ctypes.c_bool

        self.lib.webview_unbind.argtypes = [ctypes.c_void_p, ctypes.c_char_p]
        self.lib.webview_unbind.restype = ctypes.c_bool

        self.lib.webview_result.argtypes = [
            ctypes.c_void_p,
            ctypes.c_uint64,
            ctypes.c_bool,
            ctypes.c_char_p,
        ]

        self.lib.webview_emit.argtypes = [
            ctypes.c_void_p,
            ctypes.c_char_p,
            ctypes.c_char_p,
        ]

        self.lib.webview_invoke.argtypes = [
            ctypes.c_void_p,
            WebViewLib.INVOKE_FUNC_T,
            ctypes.c_void_p,
        ]

        self.webview_create_app = self.lib.webview_create_app
        self.webview_delete_app = self.lib.webview_delete_app
        self.webview_run_app = self.lib.webview_run_app
        self.webview_quit_app = self.lib.webview_quit_app
        self.webview_set_max_size_app = self.lib.webview_set_max_size_app
        self.webview_set_min_size_app = self.lib.webview_set_min_size_app
        self.webview_set_size_app = self.lib.webview_set_size_app
        self.webview_bind = self.lib.webview_bind
        self.webview_unbind = self.lib.webview_unbind
        self.webview_result = self.lib.webview_result
        self.webview_emit = self.lib.webview_emit
        self.webview_invoke = self.lib.webview_invoke
