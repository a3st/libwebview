package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"log"
	"os"
	"path/filepath"
	"unsafe"

	"github.com/a3st/libwebview/wrapper"
)

type App struct {
	instance wrapper.Webview
}

func (self *App) SetSize(width uint32, height uint32) {
	wrapper.Lib.WebviewSetSizeApp(self.instance, width, height)
}

func (self *App) SetMaxSize(width uint32, height uint32) {
	wrapper.Lib.WebviewSetMaxSizeApp(self.instance, width, height)
}

func (self *App) SetMinSize(width uint32, height uint32) {
	wrapper.Lib.WebviewSetMinSizeApp(self.instance, width, height)
}

func (self *App) Run(filePath string) {
	ex, _ := os.Executable()
	var filePathFull string = fmt.Sprintf("file:///%s/%s", filepath.Dir(ex), filePath)

	wrapper.Lib.WebviewRunApp(self.instance, filePathFull)
}

func (self *App) Quit() {
	wrapper.Lib.WebviewQuitApp(self.instance)
}

func (self *App) Bind(funcName string, callback func(args []any) []any) {
	bindFunc := wrapper.BindFunc(func(context uintptr, index uint64, data *byte) uintptr {
		argsBytes, _, _ := bytes.Cut(unsafe.Slice(data, 1024), []byte{0})

		args := []any{}
		e := json.Unmarshal(argsBytes, &args)

		if e != nil {
			log.Fatal(e)
		}

		ret := callback(args)
		jsonBytes, e := json.Marshal(ret)

		if e != nil {
			log.Fatal(e)
		}

		wrapper.Lib.WebviewResult(self.instance, index, true, string(jsonBytes))
		return 0
	})
	wrapper.Lib.WebviewBind(self.instance, funcName, bindFunc)
}

func (self *App) Emit(eventName string, data []any) {
	jsonBytes, e := json.Marshal(data)

	if e != nil {
		log.Fatal(e)
	}

	wrapper.Lib.WebviewEmit(self.instance, eventName, string(jsonBytes))
}

func Initialize(libPath string) {
	wrapper.Initialize(libPath)
}

func Deinitialize() {
	wrapper.Deinitialize()
}

func CreateApp(appName string, title string, width uint32, height uint32, resizeable bool, isDebug bool) (*App, error) {
	instance, e := wrapper.Lib.WebviewCreateApp(appName, title, width, height, resizeable, isDebug)

	if e != nil {
		return nil, e
	} else {
		return &App{instance: instance}, nil
	}
}

func DeleteApp(app *App) {
	wrapper.Lib.WebviewDeleteApp(app.instance)
}
