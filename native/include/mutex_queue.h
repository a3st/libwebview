// Copyright © 2022-2023 Dmitriy Lukovenko. All rights reserved.

#pragma once

template<typename Type>
class MutexQueue {
public:

    MutexQueue() = default;

    ~MutexQueue() = default;

    auto pop_front() -> Type {
        std::lock_guard lock(mutex);
        Type element = std::move(queue.front());
        queue.pop();
        return element;
    }

    auto push(Type&& element) -> void {
        std::lock_guard lock(mutex);
        queue.push(std::move(element));
    }

    auto empty() -> bool {
        return queue.empty();
    }

private:
    std::mutex mutex;
    std::queue<Type> queue;
};