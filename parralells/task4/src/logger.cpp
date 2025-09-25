#include "logger.h"

#include <mutex>

namespace logger {
void Logger::push(utils::Message const& message) {
    std::lock_guard lk(m);
    messages_.push(message);
    condition_.notify_one();
}

void Logger::push_with_size(utils::Message const& message) {
    std::unique_lock<std::mutex> lk(m);
    if (messages_.size() < size_of_queue) {
        messages_.push(message);
        condition_.notify_one();
    } else {
        std::cout << "Queue overflow\n";
        condition_.notify_one();
        cond_to_push.wait(lk, [this] { return messages_.size() < size_of_queue; });
        messages_.push(message);
        condition_.notify_one();
    }
    lk.unlock();
}

void Logger::end_of_work() {
    std::lock_guard lk(m);
    ++count_of_ended_threads;
}

void Logger::log(int quantity_of_threads) {
    while (true) {
        std::unique_lock<std::mutex> lock(m);
        condition_.wait(lock, [this] { return !messages_.empty(); });
        while (!messages_.empty()) {
            utils::Message message = messages_.front();
            messages_.pop();
            std::cout << message.to_string();
        }
        if (count_of_ended_threads == quantity_of_threads) {
            break;
        }
        lock.unlock();
    }
}

void Logger::log_with_size_of_queue(int quantity_of_threads) {
    while (true) {
        std::unique_lock<std::mutex> lock(m);
        condition_.wait(lock, [this] { return !messages_.empty(); });
        while (!messages_.empty()) {
            utils::Message message = messages_.front();
            messages_.pop();
            std::cout << message.to_string();
        }
        cond_to_push.notify_all();
        if (count_of_ended_threads == quantity_of_threads) {
            break;
        }
        lock.unlock();
    }
}

void Logger::push_without_condition(utils::Message const& message) {
    std::lock_guard lk(m);
    messages_.push(message);
}

void Logger::push_with_size_without_condition(utils::Message const& message) {
    std::unique_lock<std::mutex> lk(m);
    if (messages_.size() < size_of_queue) {
        messages_.push(message);
    } else {
        std::cout << "Queue overflow\n";
        while (!(messages_.size() < size_of_queue)) {
            lk.unlock();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            lk.lock();
        }
        messages_.push(message);
    }
    lk.unlock();
}

void Logger::log_without_condition(int quantity_of_threads) {
    m.lock();
    while (count_of_ended_threads < quantity_of_threads) {
        while (!messages_.empty()) {
            utils::Message message = messages_.front();
            messages_.pop();
            std::cout << message.to_string();
        }
        m.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        m.lock();
    }

    while (!messages_.empty()) {
        utils::Message message = messages_.front();
        messages_.pop();
        std::cout << message.to_string();
    }
    m.unlock();
}
}  // namespace logger
