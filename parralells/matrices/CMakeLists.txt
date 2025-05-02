cmake_minimum_required(VERSION 3.30)
project(matrices)

set(CMAKE_CXX_STANDARD 17)

add_executable(matrices src/main.cpp
        src/matrix.cpp
        src/matrix.h
        src/evals.h
        src/evals.cpp)
