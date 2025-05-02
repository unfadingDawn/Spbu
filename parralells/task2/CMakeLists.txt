cmake_minimum_required(VERSION 3.30)
project(task2)

set(CMAKE_CXX_STANDARD 17)

add_executable(task2 src/main.cpp
        src/util.cpp
        src/util.h
        src/program.h)
