package main

import (
	"testing"
	"time"
)

func TestApp(t *testing.T) {
	Initialize("lib/x86_64/")

	app, _ := CreateApp("test_app_go", "Test App Golang", 800, 600, false, true)

	app.Bind("app_close", func(args []any) []any {
		app.Quit()
		return []any{}
	})

	app.Bind("get_message", func(args []any) []any {
		app.Emit("update_time", []any{time.Now().Format("01-02-2006")})
		return []any{"Привет из libwebview!"}
	})

	app.Run("resources/index.html")

	Deinitialize()
}
