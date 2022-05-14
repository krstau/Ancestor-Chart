cmake_minimum_required(VERSION 3.15)
project(ancestor_chart)

set(CMAKE_CXX_STANDARD 17)

add_executable(ancestor_chart main.cpp Person.cpp)

set(SOURCE_FILES
        main.cpp
        Person.cpp
        #my_file_to_exclude.cpp
        )