webview.event('update_time', (data) => {
    let element = document.querySelector('#time');
    element.innerHTML = data;
})

function quitApp() {
    webview.invoke('app_close');
}

window.onload = () => {
    webview.invoke('get_message').then(
        (data) => {
            let element = document.querySelector('#message');
            element.innerHTML = data;
        }
    )
}