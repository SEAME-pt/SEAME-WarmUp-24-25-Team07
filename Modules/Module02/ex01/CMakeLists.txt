cmake_minimum_required(VERSION 3.10)
project(Module02_ex01-modularity)

set(CMAKE_CXX_STANDARD 17)

add_executable(parts sources/main.cpp sources/ACar.cpp sources/SomeCar.cpp sources/Part.cpp sources/partAll.cpp)

target_include_directories(parts PUBLIC includes)

enable_testing()

add_test(NAME Runs COMMAND parts)
