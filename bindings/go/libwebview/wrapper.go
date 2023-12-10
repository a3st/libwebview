package main

import (
	"errors"
	"fmt"
	"os"
	"path/filepath"
	"syscall"
	"unsafe"
)

const (
	WebviewCreateAppFunc     = "webview_create_app"
	WebviewDeleteAppFunc     = "webview_delete_app"
	WebviewRunAppFunc        = "webview_run_app"
	WebviewQuitAppFunc       = "webview_quit_app"
	WebviewSetMaxSizeAppFunc = "webview_set_max_size_app"
	WebviewSetMinSizeAppFunc = "webview_set_min_size_app"
	WebviewSetSizeAppFunc    = "webview_set_size_app"
	WebviewBindFunc          = "webview_bind"
	WebviewResultFunc        = "webview_result"
	WebviewEmitFunc          = "webview_emit"
)

type Webview uintptr

type Wrapper struct {
	library syscall.Handle

	webviewCreateAppPtr     uintptr
	webviewDeleteAppPtr     uintptr
	webviewRunAppPtr        uintptr
	webviewQuitAppPtr       uintptr
	webviewSetMaxSizeAppPtr uintptr
	webviewSetMinSizeAppPtr uintptr
	webviewSetSizeAppPtr    uintptr
	webviewBindPtr          uintptr
	webviewResultPtr        uintptr
	webviewEmitPtr          uintptr
}

var wrapper *Wrapper

func Initialize() {
	wrapper = &Wrapper{}

	// Need TODO
	wrapper.library, _ = syscall.LoadLibrary("lib/x86_64/WebViewEdge.dll")

	wrapper.webviewCreateAppPtr, _ = syscall.GetProcAddress(wrapper.library, WebviewCreateAppFunc)
	wrapper.webviewDeleteAppPtr, _ = syscall.GetProcAddress(wrapper.library, WebviewDeleteAppFunc)
	wrapper.webviewRunAppPtr, _ = syscall.GetProcAddress(wrapper.library, WebviewRunAppFunc)
	wrapper.webviewQuitAppPtr, _ = syscall.GetProcAddress(wrapper.library, WebviewQuitAppFunc)
	wrapper.webviewSetMaxSizeAppPtr, _ = syscall.GetProcAddress(wrapper.library, WebviewSetMaxSizeAppFunc)
	wrapper.webviewSetMinSizeAppPtr, _ = syscall.GetProcAddress(wrapper.library, WebviewSetMinSizeAppFunc)
	wrapper.webviewSetSizeAppPtr, _ = syscall.GetProcAddress(wrapper.library, WebviewSetSizeAppFunc)
	wrapper.webviewBindPtr, _ = syscall.GetProcAddress(wrapper.library, WebviewBindFunc)
	wrapper.webviewResultPtr, _ = syscall.GetProcAddress(wrapper.library, WebviewResultFunc)
	wrapper.webviewEmitPtr, _ = syscall.GetProcAddress(wrapper.library, WebviewEmitFunc)
}

func Deinitialize() {
	_ = syscall.FreeLibrary(wrapper.library)
}

func (self *Wrapper) WebviewCreateApp(appName string, title string, width uint32, height uint32, resizeable bool, isDebug bool) (Webview, error) {
	appNameBytes, _ := syscall.BytePtrFromString(appName)
	titleBytes, _ := syscall.BytePtrFromString(title)

	var resizeableInt uint32
	if resizeable {
		resizeableInt = 1
	} else {
		resizeableInt = 0
	}

	var isDebugInt uint32
	if isDebug {
		isDebugInt = 1
	} else {
		isDebugInt = 0
	}

	ret, _, _ := syscall.SyscallN(
		uintptr(self.webviewCreateAppPtr),
		uintptr(unsafe.Pointer(appNameBytes)),
		uintptr(unsafe.Pointer(titleBytes)),
		uintptr(width),
		uintptr(height),
		uintptr(resizeableInt),
		uintptr(isDebugInt))

	if ret != 0 {
		return Webview(ret), nil
	} else {
		return Webview(0), errors.New("Error during creation WebView")
	}
}

func (self *Wrapper) WebviewDeleteApp(instance Webview) {
	_, _, _ = syscall.SyscallN(
		uintptr(self.webviewDeleteAppPtr),
		uintptr(instance))
}

func (self *Wrapper) WebviewRunApp(instance Webview, filePath string) {
	ex, _ := os.Executable()

	var filePathFull string = fmt.Sprintf("file:///%s/%s", filepath.Dir(ex), filePath)
	filePathFullBytes, _ := syscall.BytePtrFromString(filePathFull)

	_, _, _ = syscall.SyscallN(
		uintptr(self.webviewRunAppPtr),
		uintptr(instance),
		uintptr(unsafe.Pointer(filePathFullBytes)))
}
