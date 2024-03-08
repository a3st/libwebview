// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

namespace libwebview
{
    template <typename Type>
    class ConcurrentQueue
    {
      public:
        ConcurrentQueue() = default;

        auto pop_front() -> Type
        {
            std::unique_lock lock(mutex);
            while (queue.empty())
            {
                condition.wait(lock);
            }
            Type element = std::move(queue.front());
            queue.pop();
            return element;
        }

        auto push(Type&& element) -> void
        {
            std::lock_guard lock(mutex);
            queue.push(std::move(element));
            condition.notify_one();
        }

        auto empty() const -> bool
        {
            std::lock_guard lock(mutex);
            return queue.empty();
        }

        auto size() const -> size_t
        {
            std::lock_guard lock(mutex);
            return queue.size();
        }

      private:
        mutable std::mutex mutex;
        std::queue<Type> queue;
        std::condition_variable condition;
    };
} // namespace libwebview