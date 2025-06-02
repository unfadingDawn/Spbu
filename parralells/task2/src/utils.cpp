#include "utils.h"

#include <algorithm>
#include <cstdlib>

namespace utils {
    std::vector<int> get_rand_indexes(const int range) {
        std::vector<int> indices(3);
        for (int i = 0; i < 3; i++) {
            int index = rand() % range;
            while (std::find(indices.begin(), indices.end(), index) != indices.end()) {
                index = rand() % range;
            }
            indices[i] = index;
        }
        return indices;
    }
    std::vector<int> get_random_array(const int size) {
        std::vector<int> indices(size);
        for (int i = 0; i < size; i++) {
            indices[i] = rand() % 100;
        }
        return indices;
    }
}
