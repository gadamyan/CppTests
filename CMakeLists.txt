cmake_minimum_required(VERSION 3.21.0)

project(CppTests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(core)
add_subdirectory(test)

enable_testing()
add_test(NAME test COMMAND core_test)