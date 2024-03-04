import json
import os
from .wrapper import WebViewLib

lib = WebViewLib()


class App:
    def __init__(
        self,
        app_name: str,
        title: str,
        size: tuple[int, int],
        resizeable: bool = False,
        is_debug: bool = True,
    ):
        self.callbacks = []

        width, height = size

        self.instance = lib.webview_create_app(
            app_name.encode(), title.encode(), width, height, resizeable, is_debug
        )

    def __del__(self):
        lib.webview_delete_app(self.instance)

    def set_max_size(self, size: tuple[int, int]):
        width, height = size
        lib.webview_set_max_size_app(self.instance, width, height)

    def set_min_size(self, size: tuple[int, int]):
        width, height = size
        lib.webview_set_min_size_app(self.instance, width, height)

    def set_size(self, size: tuple[int, int]):
        width, height = size
        lib.webview_set_size_app(self.instance, width, height)

    def quit(self):
        lib.webview_quit_app(self.instance)

    def emit(self, event: str, args):
        data = json.dumps(args)
        lib.webview_emit(self.instance, event.encode(), data.encode())

    def route(self, func):
        def wrapper(ctx, index, args):
            data = json.loads(args)

            try:
                if len(data) == 0:
                    ret = func()
                else:
                    ret = func(*data)

                if ret is not None:
                    data = json.dumps(ret)
                    lib.webview_result(self.instance, index, True, data.encode())
                else:
                    lib.webview_result(self.instance, index, True, "{}".encode())

            except Exception as e:
                data = json.dumps({"error": str(e)})
                lib.webview_result(self.instance, index, False, data.encode())

        self.callbacks.append(
            WebViewLib.BIND_FUNC_T(lambda ctx, index, args: wrapper(ctx, index, args))
        )

        lib.webview_bind(
            self.instance, func.__name__.encode(), self.callbacks[-1], None
        )
        return wrapper

    def run(self, file_path: str, callback=None):
        if callback is None:
            lib.webview_run_app(
                self.instance,
                ("file:///" + file_path).encode(),
                WebViewLib.CUSTOM_UPDATE_FUNC_T(),
                None,
            )
        else:
            lib.webview_run_app(
                self.instance,
                ("file:///" + file_path).encode(),
                WebViewLib.CUSTOM_UPDATE_FUNC_T(lambda ctx: callback()),
                None,
            )
