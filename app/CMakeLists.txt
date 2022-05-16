add_executable(app main.cpp ../tests/PersonTest.cpp)

target_compile_features(app PRIVATE cxx_std_17)

target_link_libraries(app PRIVATE source_library)