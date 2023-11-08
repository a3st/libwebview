
ABOVE.event('test_event', (data) => {
    console.log(data)
})

function test() {
    ABOVE.window_close([ 1, 2, 3, 4, 5, { 'test': 2 } ]).then(
        (result) => {
            console.log(result)
        },
        (result) => {
            console.log(result.error)
        }
    )
}
