#include "utils.h"

#include <fstream>
#include <iostream>
#include <ostream>

namespace utils {
    void add_nums(multithread_container::HashMap &hash_map, const int start_num, const int end_num) {
        const auto val = multithread_container::BaseValue("Hello", 10);
        for (int i = start_num; i <= end_num; i++) {
            multithread_container::HashMap::put(hash_map, i, val);
        }
    }

    void remove_nums(multithread_container::HashMap &hash_map, const int start_num, const int end_num) {
        for (int i = start_num; i <= end_num; i++) {
            multithread_container::HashMap::remove(hash_map, i);
        }
    }

    void check_nums(multithread_container::HashMap &hash_map, const int start_num, const int end_num) {
        for (int i = start_num; i <= end_num; i++) {
            bool found = multithread_container::HashMap::check(hash_map, i);
            std::ofstream file("test.txt", std::ios::out | std::ios::app);
            if (found) {
                file << "found\n";
            }else {
                file << "not found\n";
            }
            file.close();
        }
    }
}
