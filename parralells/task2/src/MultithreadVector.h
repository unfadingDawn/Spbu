#pragma once
#include <mutex>
#include <vector>
#include "utils.h"

namespace multithread_vector {
    class MultithreadVector {
        private:
            std::vector<int> numbers;
            std::vector<std::mutex> mutexes;
        public:
            explicit MultithreadVector(const std::vector<int>& numbers): numbers(numbers), mutexes(numbers.size()) {};
            static void GetRandomSum(MultithreadVector &vector);
            int GetNumber(int pos);
            [[nodiscard]] std::size_t size() const;
    };
}
