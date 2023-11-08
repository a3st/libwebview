// Copyright © 2022-2023 Dmitriy Lukovenko. All rights reserved.

#pragma once

class ThreadQueue {
public:

    ThreadQueue();

    ~ThreadQueue();

    template<typename Func, typename... Args>
    void push_task(Func&& func, Args&&... args) {
        task_func_t task = std::bind(func, std::forward<Args>(args)...);
        std::unique_lock lock(mutex);
        queue.push(task);
        cv.notify_one();
    }

    void loop();

private:

    std::thread thread;
    bool running;

    using task_func_t = std::function<void()>;
    std::queue<task_func_t> queue;

    std::mutex mutex;
    std::condition_variable cv;
};