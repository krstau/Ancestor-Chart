include_directories("${PROJECT_SOURCE_DIR}/include")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

add_executable(NodeTest NodeTest.cpp)
add_executable(PersonTest PersonTest.cpp)
add_executable(DateTest DateTest.cpp)
