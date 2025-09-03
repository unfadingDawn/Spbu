#include <iostream>
#include <thread>
#include <bits/ostream.tcc>

#include "src/HashMap.h"
#include "src/utils.h"

int main() {
    std::vector<std::thread> threads;
    const int a = 500;
    auto map = multithread_container::HashMap(a);
    threads.emplace_back(utils::add_nums, std::ref(map), 1, 100);
    threads.emplace_back(utils::add_nums, std::ref(map), 101, 200);
    threads.emplace_back(utils::add_nums, std::ref(map), 201, 300);
    threads.emplace_back(utils::add_nums, std::ref(map), 301, 400);
    threads.emplace_back(utils::add_nums, std::ref(map), 401, 500);
    threads.emplace_back(utils::add_nums, std::ref(map), 501, 600);
    threads.emplace_back(utils::add_nums, std::ref(map), 601, 700);
    threads.emplace_back(utils::add_nums, std::ref(map), 701, 800);
    threads.emplace_back(utils::add_nums, std::ref(map), 801, 900);
    threads.emplace_back(utils::add_nums, std::ref(map), 901, 1000);
    for (auto& thread : threads) {
        thread.join();
    }
    for (int i = 0; i < 1000; i++) {
        if (!multithread_container::HashMap::check(map, i + 1)) {
            std::cout << i << '\n';
        }
    }
    threads.emplace_back(utils::add_nums, std::ref(map), 1001, 1100);
    threads.emplace_back(utils::add_nums, std::ref(map), 1101, 1200);
    threads.emplace_back(utils::remove_nums, std::ref(map), 100, 250);
    threads.emplace_back(utils::remove_nums, std::ref(map), 250, 500);
    threads.emplace_back(utils::check_nums, std::ref(map), 100, 240);
    threads.emplace_back(utils::check_nums, std::ref(map), 240, 500);
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    for (int i = 100; i < 500; i++) {
        if (!multithread_container::HashMap::check(map, i + 1)) {
            std::cout << i << '\n';
        }
    }

    return 0;
}
