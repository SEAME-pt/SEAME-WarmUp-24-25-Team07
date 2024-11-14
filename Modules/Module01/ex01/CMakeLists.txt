cmake_minimum_required(VERSION 3.10)
project(Module01_ex01)

set(CMAKE_CXX_STANDARD 17)

add_executable(Module01_ex01 main.cpp Car.cpp SportCar.cpp)

target_include_directories(Module01_ex01 PUBLIC .)

enable_testing()

add_test(NAME Runs COMMAND Module01_ex01)
