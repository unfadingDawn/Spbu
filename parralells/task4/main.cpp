#include <string>
#include <thread>
#include <fstream>

#include "src/logger.h"
#include "src/message.h"
#include "src/utils.h"

int main() {
    // Init variables
    logger::Logger logger;
    std::string message1 = "Logging 1st message\n";
    std::string message2 = "Logging 2nd message\n";
    std::string message3 = "Logging 3rd message\n";

    utils::Message log1(message1);
    utils::Message log2(message2);
    utils::Message log3(message3);

    auto start = std::chrono::high_resolution_clock::now();
    // logging with condition_variable, queue without size
    // std::thread log_thread(&logger::Logger::log, &logger, 3);
    // std::thread worker1(utils::log_message, log1, &logger);
    // std::thread worker2(utils::log_message, log2, &logger);
    // std::thread worker3(utils::log_message, log3, &logger);
    // worker1.join();
    // worker2.join();
    // worker3.join();
    // log_thread.join();

    // logging with condition_variable, queue with size
    // std::thread log_thread(&logger::Logger::log_with_size_of_queue, &logger, 9);
    // std::thread worker1(utils::log_message_with_queue, log1, &logger);
    // std::thread worker2(utils::log_message_with_queue, log2, &logger);
    // std::thread worker3(utils::log_message_with_queue, log3, &logger);
    // std::thread worker4(utils::log_message_with_queue, log1, &logger);
    // std::thread worker5(utils::log_message_with_queue, log2, &logger);
    // std::thread worker6(utils::log_message_with_queue, log3, &logger);
    // std::thread worker7(utils::log_message_with_queue, log1, &logger);
    // std::thread worker8(utils::log_message_with_queue, log2, &logger);
    // std::thread worker9(utils::log_message_with_queue, log3, &logger);
    // worker1.join();
    // worker2.join();
    // worker3.join();
    // worker4.join();
    // worker5.join();
    // worker6.join();
    // worker7.join();
    // worker8.join();
    // worker9.join();
    // log_thread.join();

    // logging without condition_variable, queue without size
    // std::thread worker1(utils::log_message_without_condition, log1, &logger);
    // std::thread worker2(utils::log_message_without_condition, log2, &logger);
    // std::thread worker3(utils::log_message_without_condition, log3, &logger);
    // std::thread log_thread(&logger::Logger::log_without_condition, &logger, 3);
    // worker1.join();
    // worker2.join();
    // worker3.join();
    // log_thread.join();

    // logging without condition_variable, queue with size
    std::thread worker1(utils::log_message_with_queue_without_condition, log1, &logger);
    std::thread worker2(utils::log_message_with_queue_without_condition, log2, &logger);
    std::thread worker3(utils::log_message_with_queue_without_condition, log3, &logger);
    std::thread worker4(utils::log_message_with_queue_without_condition, log1, &logger);
    std::thread worker5(utils::log_message_with_queue_without_condition, log2, &logger);
    std::thread worker6(utils::log_message_with_queue_without_condition, log3, &logger);
    std::thread worker7(utils::log_message_with_queue_without_condition, log1, &logger);
    std::thread worker8(utils::log_message_with_queue_without_condition, log2, &logger);
    std::thread worker9(utils::log_message_with_queue_without_condition, log3, &logger);
    std::thread log_thread(&logger::Logger::log_without_condition, &logger, 9);
    worker1.join();
    worker2.join();
    worker3.join();
    worker4.join();
    worker5.join();
    worker6.join();
    worker7.join();
    worker8.join();
    worker9.join();
    log_thread.join();
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    const std::string filename = "time.txt";
    std::ofstream outputFile(filename, std::ios::app);
    outputFile << "Execution time: " << elapsed.count() << " seconds\n";
    outputFile.close();
}
