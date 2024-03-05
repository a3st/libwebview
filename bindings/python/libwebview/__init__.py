import json
from .wrapper import WebViewLib

lib = WebViewLib()


class App:
    def __init__(
        self,
        app_name: str,
        title: str,
        size: tuple[int, int],
        resizeable: bool = False,
        debug_mode: bool = True,
    ):
        self.callbacks = []

        width, height = size

        self.instance = lib.webview_create_app(
            app_name.encode(), title.encode(), width, height, resizeable, debug_mode
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

    def invoke(self, func):
        lib.webview_invoke(self.instance, WebViewLib.INVOKE_FUNC_T(lambda ctx: func()))

    def bind(self, func):
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

    def run(self, url: str):
        lib.webview_run_app(self.instance, url.encode())
