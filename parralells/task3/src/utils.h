#pragma once
#include "HashMap.h"

namespace utils {
    void add_nums(multithread_container::HashMap& hash_map, int start_num, int end_num);
    void remove_nums(multithread_container::HashMap& hash_map, const int start_num, const int end_num);
    void check_nums(multithread_container::HashMap& hash_map, const int start_num, const int end_num);
}
