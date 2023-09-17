
function test() {
    webUI.window_close([ 1, 2, 3, 4, 5, { 'test': 2 } ]).then(
        (result) => {
            console.log(result)
        },
        (result) => {
            console.log(result.error)
        }
    )
}
