#include <fstream>
#include <iostream>
#include <vector>

#include "evals.h"
#include "matrix.h"

int main(int argc, char* argv[]) {
    int sizeMatrix = std::atoi(argv[1]);
    math::Matrix matrix = math::GenMatrix(sizeMatrix);
    // matrix = std::vector<std::vector<int>>{
    //     {0, 2, 3, 4, 7, 8, 4 },
    //     {5, 4, 6, 8, 7, 9, 4 },
    //     {8, 7, 4, 5, 2, 1, 3 },
    //     {5, 4, 4, 5, 6, 2, 1},
    //     {4, 5, 2, 1, 8, 9, 6},
    //     {12, 5, 2, 1, 2, 9, 3},
    //     {1, 1, 1, 1, 1, 1, 1 }
    // };
    // matrix = std::vector<std::vector<int>>{
    //     {3, 3, 2, 1, 7},
    //     {2, 1, 3, 4, 5},
    //     {7, 9, 3, 7, 2},
    //     {5, 4, 4, 5, 6},
    //     {1, 2, 3, 4, 5}
    // };

    // matrix = std::vector<std::vector<int>>{
    //     {3, 3, 2},
    //     {1, 7, 2},
    //     {1, 3, 4}
    // };
    int res = 0;
    int level = std::atoi(argv[2]);
    auto time = math::Bench(math::Determinant, matrix, res, level);
    std::ofstream file("bench.txt", std::ios::out | std::ios::app);
    file << sizeMatrix << "x" << sizeMatrix << "\n" << "level: " << level << '\n' << time << " milliseconds\n" << res << "\n\n";
    file.close();
}
