#pragma once

#include <functional>
#include <thread>

#include "matrix.h"

namespace math {
void Determinant(Matrix const& matrix, int& res, int level = 0);
long Bench(std::function<void(Matrix const&, int&, int)> const& func, Matrix const& matrix,
           int& res, int level);
Matrix GenMatrix(int n);
}  // namespace math