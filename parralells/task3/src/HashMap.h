#pragma once
#include <vector>

#include "KeyValue.h"

namespace multithread_container {
class HashMap {
private:
    int size_of_buckets_;
    std::vector<List> buckets_;
    std::vector<std::mutex> mutexes_;

public:
    explicit HashMap(int const size_of_buckets)
        : size_of_buckets_(size_of_buckets), buckets_(size_of_buckets), mutexes_(size_of_buckets) {}

    HashMap(HashMap const &map)
        : size_of_buckets_(map.size_of_buckets_),
          buckets_(map.buckets_),
          mutexes_(map.size_of_buckets_) {}

    static void put(HashMap &map, int hash, BaseValue const &value);
    static void remove(HashMap &map, int hash);
    static bool check(HashMap &map, int hash);

    [[nodiscard]] int hash_func(int const hash) const {
        return hash % size_of_buckets_;
    }
};
}  // namespace multithread_container