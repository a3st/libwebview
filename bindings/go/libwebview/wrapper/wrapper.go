package wrapper

import (
	"errors"
	"fmt"
	"log"
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
type BindFunc func(context uintptr, index uint64, data *byte) uintptr

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

var Lib *Wrapper

func Initialize(libPath string) {

	libPathFull := fmt.Sprintf("%sWebViewEdge.dll", libPath)
	library, e := syscall.LoadLibrary(libPathFull)

	if e != nil {
		log.Fatal(e)
	}

	Lib = &Wrapper{}
	Lib.library = library
	Lib.webviewCreateAppPtr, _ = syscall.GetProcAddress(Lib.library, WebviewCreateAppFunc)
	Lib.webviewDeleteAppPtr, _ = syscall.GetProcAddress(Lib.library, WebviewDeleteAppFunc)
	Lib.webviewRunAppPtr, _ = syscall.GetProcAddress(Lib.library, WebviewRunAppFunc)
	Lib.webviewQuitAppPtr, _ = syscall.GetProcAddress(Lib.library, WebviewQuitAppFunc)
	Lib.webviewSetMaxSizeAppPtr, _ = syscall.GetProcAddress(Lib.library, WebviewSetMaxSizeAppFunc)
	Lib.webviewSetMinSizeAppPtr, _ = syscall.GetProcAddress(Lib.library, WebviewSetMinSizeAppFunc)
	Lib.webviewSetSizeAppPtr, _ = syscall.GetProcAddress(Lib.library, WebviewSetSizeAppFunc)
	Lib.webviewBindPtr, _ = syscall.GetProcAddress(Lib.library, WebviewBindFunc)
	Lib.webviewResultPtr, _ = syscall.GetProcAddress(Lib.library, WebviewResultFunc)
	Lib.webviewEmitPtr, _ = syscall.GetProcAddress(Lib.library, WebviewEmitFunc)
}

func Deinitialize() {
	_ = syscall.FreeLibrary(Lib.library)
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

func (self *Wrapper) WebviewRunApp(instance Webview, url string) {
	urlBytes, _ := syscall.BytePtrFromString(url)

	_, _, _ = syscall.SyscallN(
		uintptr(self.webviewRunAppPtr),
		uintptr(instance),
		uintptr(unsafe.Pointer(urlBytes)))
}

func (self *Wrapper) WebviewQuitApp(instance Webview) {
	_, _, _ = syscall.SyscallN(
		uintptr(self.webviewQuitAppPtr),
		uintptr(instance))
}

func (self *Wrapper) WebviewSetMaxSizeApp(instance Webview, width uint32, height uint32) {
	_, _, _ = syscall.SyscallN(
		uintptr(self.webviewSetMaxSizeAppPtr),
		uintptr(instance),
		uintptr(width),
		uintptr(height))
}

func (self *Wrapper) WebviewSetMinSizeApp(instance Webview, width uint32, height uint32) {
	_, _, _ = syscall.SyscallN(
		uintptr(self.webviewSetMinSizeAppPtr),
		uintptr(instance),
		uintptr(width),
		uintptr(height))
}

func (self *Wrapper) WebviewSetSizeApp(instance Webview, width uint32, height uint32) {
	_, _, _ = syscall.SyscallN(
		uintptr(self.webviewSetSizeAppPtr),
		uintptr(instance),
		uintptr(width),
		uintptr(height))
}

func (self *Wrapper) WebviewEmit(instance Webview, eventName string, data string) {
	eventNameBytes, _ := syscall.BytePtrFromString(eventName)
	dataBytes, _ := syscall.BytePtrFromString(data)

	_, _, _ = syscall.SyscallN(
		uintptr(self.webviewEmitPtr),
		uintptr(instance),
		uintptr(unsafe.Pointer(eventNameBytes)),
		uintptr(unsafe.Pointer(dataBytes)))
}

func (self *Wrapper) WebviewResult(instance Webview, index uint64, success bool, data string) {
	dataBytes, _ := syscall.BytePtrFromString(data)

	var successInt uint32
	if success {
		successInt = 1
	} else {
		successInt = 0
	}

	_, _, _ = syscall.SyscallN(
		uintptr(self.webviewResultPtr),
		uintptr(instance),
		uintptr(index),
		uintptr(successInt),
		uintptr(unsafe.Pointer(dataBytes)))
}

func (self *Wrapper) WebviewBind(instance Webview, funcName string, callback BindFunc) {
	funcNameBytes, _ := syscall.BytePtrFromString(funcName)
	callbackPtr := syscall.NewCallback(callback)

	_, _, _ = syscall.SyscallN(
		uintptr(self.webviewBindPtr),
		uintptr(instance),
		uintptr(unsafe.Pointer(funcNameBytes)),
		callbackPtr,
		uintptr(unsafe.Pointer(nil)))
}
