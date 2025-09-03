#pragma once
#include <condition_variable>
#include <iostream>
#include <queue>

#include "message.h"

namespace logger {
    class Logger {
    private:
        std::queue<utils::Message> messages_;
        std::condition_variable condition_;
    public:
        explicit Logger(): messages_() {};
        void push(const utils::Message& message) {
            messages_.push(message);
            condition_.notify_one();
        }
        void log(std::mutex m) {
            std::unique_lock<std::mutex> lock(m);
            condition_.wait(lock);

            while (!messages_.empty()) {
                utils::Message message = messages_.front();
                messages_.pop();
                std::cout << message.to_string();
            }

        }
    };

}
