cmake_minimum_required(VERSION 3.10)

# Set the project name
project(PhoneBook)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the directory for header files
include_directories(include)

# Add the executable
add_executable(PhoneBook sources/main.cpp sources/PhoneBook.cpp sources/Contact.cpp)

# Add the tests directory
add_subdirectory(tests)

# Link the testing framework
target_link_libraries(PhoneBook gtest gtest_main)
