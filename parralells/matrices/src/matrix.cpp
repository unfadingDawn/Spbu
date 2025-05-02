#include "matrix.h"

#include <algorithm>

namespace math {
Matrix Matrix::GetMinor(int const first_index, int const second_index) const {
    std::vector<std::vector<int>> minor_matrix;
    for (int i = 0; i < height_; i++) {
        if (i == first_index) {
            continue;
        }
        minor_matrix.emplace_back();
        for (int j = 0; j < width_; j++) {
            if (j == second_index) {
                continue;
            }
            minor_matrix.back().push_back(matrix_[i][j]);
        }
    }
    Matrix result(minor_matrix);
    return result;
}
}  // namespace math
