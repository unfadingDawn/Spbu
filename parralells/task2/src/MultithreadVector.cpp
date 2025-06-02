#include "MultithreadVector.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <unistd.h>

namespace multithread_vector {
    /* Наивная реализация без контроля блокирования mutex */
    // void MultithreadVector::GetRandomSum(MultithreadVector &vector) {
    //     const std::vector<int> indexes = utils::get_rand_indexes(vector.numbers.size());
    //     int sum = 0;
    //     for (const int index : indexes) {
    //         vector.mutexes[index].lock();
    //         sum += vector.numbers[index];
    //     }
    //     for (const int index : indexes) {
    //         vector.numbers[index] = sum;
    //     }
    //     for (const int index : indexes) {
    //         vector.mutexes[index].unlock();
    //     }
    // }

    /* mutex большей гранулярности */
    void MultithreadVector::GetRandomSum(MultithreadVector &vector) {
        std::lock_guard<std::mutex> lock(vector.mutexes[0]);
        const std::vector<int> indexes = utils::get_rand_indexes(vector.numbers.size());
        int sum = 0;
        for (const int index : indexes) {
            sum += vector.numbers[index];
        }
        for (const int index : indexes) {
            vector.numbers[index] = sum;
        }
    }

    /* try_lock с откатом */
    // void MultithreadVector::GetRandomSum(MultithreadVector &vector) {
    //     const std::vector<int> indexes = utils::get_rand_indexes(vector.numbers.size());
    //     int sum = 0;
    //     int count_locks = 0;
    //     while (count_locks < 3) {
    //         if (vector.mutexes[indexes[count_locks]].try_lock()) {
    //             ++count_locks;
    //         }else {
    //             if (!count_locks) {
    //                 continue;
    //             }
    //             --count_locks;
    //             while (count_locks) {
    //                 vector.mutexes[indexes[count_locks]].unlock();
    //                 --count_locks;
    //             }
    //             vector.mutexes[indexes[count_locks]].unlock();
    //         }
    //     }
    //     for (const int index : indexes) {
    //         sum += vector.numbers[index];
    //     }
    //     for (const int index : indexes) {
    //         vector.numbers[index] = sum;
    //     }
    //     for (const int index : indexes) {
    //         vector.mutexes[index].unlock();
    //     }
    // }


    /* Протокол - набор замков в правильном порядке */
    // void MultithreadVector::GetRandomSum(MultithreadVector &vector) {
    //     std::vector<int> indexes = utils::get_rand_indexes(vector.numbers.size());
    //     std::sort(indexes.begin(), indexes.end());
    //     int sum = 0;
    //     for (const int index : indexes) {
    //         while (!vector.mutexes[index].try_lock()) {
    //         }
    //         sum += vector.numbers[index];
    //     }
    //     for (const int index : indexes) {
    //         vector.numbers[index] = sum;
    //     }
    //     for (const int index : indexes) {
    //         vector.mutexes[index].unlock();
    //     }
    // }

    int MultithreadVector::GetNumber(const int pos) {
        if (pos >= numbers.size()) {
            throw std::out_of_range("MultithreadVector::GetNumber");
        }
        std::lock_guard<std::mutex> lock(mutexes[pos]);
        return numbers[pos];
    }
    std::size_t MultithreadVector::size() const {
        return numbers.size();
    }

}
