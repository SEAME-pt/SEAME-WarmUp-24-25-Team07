cmake_minimum_required(VERSION 3.10)
project(PhoneBookTests)

set(CMAKE_CXX_STANDARD 20)

# Add Catch2
include(FetchContent)
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.13.7
)
FetchContent_MakeAvailable(catch)

# Add the source files
set(SOURCE_FILES
    ../sources/PhoneBook.cpp
    ../sources/Contact.cpp
)

# Add the test files
add_executable(tests test_phonebook.cpp ${SOURCE_FILES})

# Link Catch2 with the test executable
target_link_libraries(tests Catch2::Catch2)