
webview.event('test_event', (data) => {
    console.log(data)
})

function quitApp() {
    webview.invoke('window_close');
}
