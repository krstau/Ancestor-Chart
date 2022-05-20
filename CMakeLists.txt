cmake_minimum_required(VERSION 3.15)

project(AncestorChart
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# compiled library here
add_subdirectory(src)

# executable file here
add_subdirectory(app)

add_subdirectory(tests)