#pragma once
#include <vector>

namespace math {
class Matrix {
private:
    std::vector<std::vector<int>> matrix_;
    std::size_t height_;
    std::size_t width_;

public:
    explicit Matrix(std::vector<std::vector<int>> const& matrix)
        : matrix_(matrix), height_(matrix.size()), width_(matrix[0].size()) {}

    [[nodiscard]] Matrix GetMinor(int first_index, int second_index) const;

    [[nodiscard]] std::vector<std::vector<int>> GetMatrix() const {
        return matrix_;
    };
};
}  // namespace math
