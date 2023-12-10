package main

func main() {
	Initialize()

	app, _ := CreateApp("test_app_go", "Test App Golang", 800, 600, false, true)

	app.Run("resources/index.html")
}
