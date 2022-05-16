cmake_minimum_required(VERSION 3.15)
project(ancestor_chart)

set(CMAKE_CXX_STANDARD 17)

add_executable(ancestor_chart src/main.cpp src/AncestorChart.cpp src/Person.cpp)