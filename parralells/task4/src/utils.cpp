#include "utils.h"

#include <cstdlib>
#include <string>
#include "message.h"
#include <iomanip>
#include <ctime>
#include <chrono>

namespace utils {
void log_message(utils::Message const& message, logger::Logger* logger) {
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 51));
        auto now = std::chrono::system_clock::now();


    // Convert to time_t for use with std::localtime
    std::time_t time_t_now = std::chrono::system_clock::to_time_t(now);

    // Convert to local time structure
    std::tm* local_tm = std::localtime(&time_t_now);

    // Get milliseconds component
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()
    ).count() % 1000;

    // Create a stringstream to format the time
    std::stringstream ss;

    ss << std::put_time(local_tm, "%Y-%m-%d %H:%M:%S")
              << "."
              << std::setfill('0') << std::setw(3) << milliseconds
              << std::endl;

    // Get the formatted time string
    std::string time_string = ss.str();
    utils::Message mes(time_string);
	logger->push(mes);

    }
    logger->end_of_work();
}

void log_message_with_queue(utils::Message const& message, logger::Logger* logger) {
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 51));
auto now = std::chrono::system_clock::now();


    // Convert to time_t for use with std::localtime
    std::time_t time_t_now = std::chrono::system_clock::to_time_t(now);

    // Convert to local time structure
    std::tm* local_tm = std::localtime(&time_t_now);

    // Get milliseconds component
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()
    ).count() % 1000;

    // Create a stringstream to format the time
    std::stringstream ss;

    ss << std::put_time(local_tm, "%Y-%m-%d %H:%M:%S")
              << "."
              << std::setfill('0') << std::setw(3) << milliseconds
              << std::endl;

    // Get the formatted time string
    std::string time_string = ss.str();
    utils::Message mes(time_string);

        logger->push_with_size(mes);
    }
    logger->end_of_work();
}

void log_message_without_condition(utils::Message const& message, logger::Logger* logger) {
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 51));
auto now = std::chrono::system_clock::now();


    // Convert to time_t for use with std::localtime
    std::time_t time_t_now = std::chrono::system_clock::to_time_t(now);

    // Convert to local time structure
    std::tm* local_tm = std::localtime(&time_t_now);

    // Get milliseconds component
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()
    ).count() % 1000;

    // Create a stringstream to format the time
    std::stringstream ss;

    ss << std::put_time(local_tm, "%Y-%m-%d %H:%M:%S")
              << "."
              << std::setfill('0') << std::setw(3) << milliseconds
              << std::endl;

    // Get the formatted time string
    std::string time_string = ss.str();
    utils::Message mes(time_string);

        logger->push_without_condition(mes);
    }
    logger->end_of_work();
}

void log_message_with_queue_without_condition(utils::Message const& message,
                                              logger::Logger* logger) {
    for (int i = 0; i < 5; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 51));
auto now = std::chrono::system_clock::now();


    // Convert to time_t for use with std::localtime
    std::time_t time_t_now = std::chrono::system_clock::to_time_t(now);

    // Convert to local time structure
    std::tm* local_tm = std::localtime(&time_t_now);

    // Get milliseconds component
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()
    ).count() % 1000;

    // Create a stringstream to format the time
    std::stringstream ss;

    ss << std::put_time(local_tm, "%Y-%m-%d %H:%M:%S")
              << "."
              << std::setfill('0') << std::setw(3) << milliseconds
              << std::endl;

    // Get the formatted time string
    std::string time_string = ss.str();
    utils::Message mes(time_string);

        logger->push_with_size_without_condition(mes);
    }
    logger->end_of_work();
}
}  // namespace utils
