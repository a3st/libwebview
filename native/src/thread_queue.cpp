// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#include "precompiled.h"
#include "thread_queue.hpp"

namespace libwebview
{
    ThreadQueue::ThreadQueue() : thread(&ThreadQueue::loop, this), running(true)
    {
    }

    ThreadQueue::~ThreadQueue()
    {
        running = false;
        thread.join();
    }

    void ThreadQueue::loop()
    {
        while (running)
        {
            task_func_t func;
            {
                std::unique_lock lock(mutex);
                cv.wait(lock, [&]() -> bool { return !queue.empty() || !running; });
                if (!running)
                {
                    continue;
                }
                func = std::move(queue.front());
                queue.pop();
            }
            func();
        }
    }
} // namespace libwebview