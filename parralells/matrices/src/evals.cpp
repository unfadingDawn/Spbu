#include "evals.h"

#include <cstdlib>
#include <mutex>

namespace math {
void Determinant(Matrix const& matrix, int& res, int level /* = 1 */) {
    auto const temp_matrix = matrix.GetMatrix();
    if (temp_matrix.size() == 1) {
        res += temp_matrix[0][0];
        return;
    }
    if (level > 0) {
        std::vector dets(temp_matrix.size(), 0);
        std::vector<std::thread> threads;
        for (int i = 0; i < temp_matrix.size(); i++) {
            auto minor = matrix.GetMinor(i, 0);
            threads.emplace_back(Determinant, minor, std::ref(dets[i]), level - 1);
        }
        for (auto& thread : threads) {
            thread.join();
        }
        for (int i = 0; i < temp_matrix.size(); i++) {
            mutexes[i].unlock();
            res += (i % 2 ? -1 : 1) * dets[i] * temp_matrix[i][0];
        }
    } else {
        for (int i = 0; i < temp_matrix.size(); i++) {
            int det = 0;
            Determinant(matrix.GetMinor(i, 0), det);
            res += (i % 2 ? -1 : 1) * temp_matrix[i][0] * det;
        }
    }
}

long Bench(std::function<void(Matrix const&, int&, int)> const& func, Matrix const& matrix,
           int& res, int level) {
    std::chrono::steady_clock::time_point const begin = std::chrono::steady_clock::now();
    func(matrix, res, level);
    std::chrono::steady_clock::time_point const end = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}

Matrix GenMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    return Matrix{matrix};
}
}  // namespace math
