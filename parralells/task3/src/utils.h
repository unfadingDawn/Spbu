#pragma once
#include "HashMap.h"

namespace utils {
void add_nums(multithread_container::HashMap &hash_map, int start_num, int end_num);
void remove_nums(multithread_container::HashMap &hash_map, int const start_num, int const end_num);
void check_nums(multithread_container::HashMap &hash_map, int const start_num, int const end_num);
}  // namespace utils
