#include "precompiled.h"
#include "thread_queue.h"

ThreadQueue::ThreadQueue() : thread(&ThreadQueue::loop, this), running(true) { }

ThreadQueue::~ThreadQueue() {
    running = false;
    thread.join();
}

void ThreadQueue::loop() {
    while(running) {
        task_func_t func;
        {
            std::unique_lock lock(mutex);
            cv.wait(lock, [&]() -> bool { return !queue.empty() || !running; });
            if(!running) {
                continue;
            }
            func = std::move(queue.front());
            queue.pop();
        }
        func();
    }
}