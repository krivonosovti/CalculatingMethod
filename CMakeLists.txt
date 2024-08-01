cmake_minimum_required(VERSION 3.27)
project(Vichi)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/local/include)

add_executable(Vichi main.cpp
        task_1/interpolationNewton.h
        task_1/implementation.cpp
        task_1/task_1.cpp
        basic_function.cpp
#        task_2/reverse_interpolation.cpp
#        task_2/root_search.h.txt
#        task_2/root_search.cpp.txt
#        task_2/task_2.h.txt
#        task_2/task_2_main.cpp.txt
        task_3/task_3main.cpp
        task_3/task_3_main.h
        task_4/task_4main.cpp
        task_4/task_4main.h
        task_5/task_5_main.cpp
        task_5/task_5_main.cpp
        task_5/task_5main.h
        task_6/task6_main.cpp
        task_6/task6_main.h
        #        task_5/doc/task_5main.cpp
        #        task_5/task_5main.h
#        task_5/task_5main.cpp
)

#add_executable(Vichi main.cpp
#        task_1/interpolationNewton.h
#        task_1/implementation.cpp
#        task_1/task_1.cpp
#        basic_function.cpp
#        task_2/reverse_interpolation.cpp
#        task_2/root_search.h
#        task_2/root_search.cpp
#        task_2/task_2.h
#        task_2/task_2_main.cpp
#        task_3/task_3main.cpp
#        task_3/task_3_main.h
#        task_4/task_4main.cpp
#        task_4/task_4main.h
#        task_5/task_5main.h
#        task_5/task_5main.cpp)

