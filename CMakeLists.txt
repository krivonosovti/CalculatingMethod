cmake_minimum_required(VERSION 3.27)
project(3course.task_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(3course task_1/main.cpp
        task_1/implementation.cpp
        basic_function.cpp
        basic_function.h
        task_2/root_search.cpp)
