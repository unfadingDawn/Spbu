#include <fstream>
#include <functional>
#include <iostream>
#include <ostream>
#include <thread>

#include "src/MultithreadVector.h"

int main() {
    int quantity_of_threads = 3;
    int size_of_array = 4;
    const std::vector<int> nums = utils::get_random_array(size_of_array);
    std::cout << '\n';
    multithread_vector::MultithreadVector vec(nums);
    std::vector<std::thread> threads;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    for (int i = 0; i < quantity_of_threads; i++) {
        threads.emplace_back(multithread_vector::MultithreadVector::GetRandomSum, std::ref(vec));
    }
    for (auto& thread : threads) {
        thread.join();
    }
    end = std::chrono::system_clock::now();
    std::ofstream file("test.txt", std::ios::out | std::ios::app);
    file << std::chrono::duration_cast<std::chrono::microseconds>((end - start)).count() <<" microseconds\n";
    file.close();
    return 0;
}