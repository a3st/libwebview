package main

type App struct {
	instance Webview
}

func (self *App) SetSize(width uint32, height uint32) {

}

func (self *App) SetMaxSize(width uint32, height uint32) {

}

func (self *App) SetMinSize(width uint32, height uint32) {

}

func (self *App) Run(filePath string) {
	wrapper.WebviewRunApp(self.instance, filePath)
}

func (self *App) Emit(eventName string, data []byte) {

}

func CreateApp(appName string, title string, width uint32, height uint32, resizeable bool, isDebug bool) (*App, error) {
	instance, e := wrapper.WebviewCreateApp(appName, title, width, height, resizeable, isDebug)

	if e != nil {
		return nil, e
	} else {
		return &App{instance: instance}, nil
	}
}

func DeleteApp(app *App) {
	wrapper.WebviewDeleteApp(app.instance)
}
