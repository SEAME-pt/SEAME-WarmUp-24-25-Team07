cmake_minimum_required(VERSION 3.10)
project(Module01_ex02-inheritance-polymorphism)

set(CMAKE_CXX_STANDARD 17)

add_executable(Module01_ex02-inheritance-polymorphism main.cpp ACar.cpp SportCar.cpp SedanCar.cpp)

target_include_directories(Module01_ex02-inheritance-polymorphism PUBLIC .)

enable_testing()

add_test(NAME Runs COMMAND Module01_ex02-inheritance-polymorphism)
