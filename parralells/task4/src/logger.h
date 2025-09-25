#pragma once
#include <condition_variable>
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

#include "message.h"

namespace logger {
class Logger {
private:
    std::mutex m;
    std::queue<utils::Message> messages_;
    int size_of_queue = 3;
    std::condition_variable condition_;
    std::condition_variable cond_to_push;
    int count_of_ended_threads = 0;

public:
    void push_without_condition(utils::Message const& message);
    void push_with_size_without_condition(utils::Message const& message);
    void push(utils::Message const& message);
    void push_with_size(utils::Message const& message);
    void end_of_work();
    void log(int quantity_of_threads);
    void log_with_size_of_queue(int quantity_of_threads);
    void log_without_condition(int quantity_of_threads);
};
}  // namespace logger
