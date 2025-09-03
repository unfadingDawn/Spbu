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
        explicit HashMap(const int size_of_buckets): size_of_buckets_(size_of_buckets), buckets_(size_of_buckets), mutexes_(size_of_buckets) {}
        HashMap(const HashMap &map): size_of_buckets_(map.size_of_buckets_),   buckets_(map.buckets_), mutexes_(map.size_of_buckets_) {}
        static void put(HashMap& map, int hash, const BaseValue& value);
        static void remove(HashMap& map, int hash);
        static bool check(HashMap &map, int hash);
        [[nodiscard]] int hash_func(const int hash) const {return hash % size_of_buckets_;}
    };
}