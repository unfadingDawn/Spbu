#include "util.h"

#include <cstdlib>
#include <stdlib.h>

namespace util {
    std::vector<int> rand_indexes(int n) {
        bool flag = true;
        std::vector<int> indexes;
        int first_index = 0;
        int second_index = 0;
        int third_index = 0;

        while (flag) {
            first_index = rand() % n;
            second_index = rand() % n;
            third_index = rand() % n;
            if (first_index == second_index) {
                break;
            }
            if (first_index == third_index) {
                break;
            }
            if (second_index == third_index) {
                break;
            }
            indexes.push_back(first_index);
            indexes.push_back(second_index);
            indexes.push_back(third_index);
            flag = false;
        }

        return indexes;
    }
}
