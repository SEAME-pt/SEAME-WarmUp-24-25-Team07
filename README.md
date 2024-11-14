
# Exercise 02 : Do you know string??

This is a C++ project developed to perform string conversion operations, such as changing between uppercase and lowercase. This project is configured with CMake and includes unit tests using `assert`.

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Compilation and Execution](#compilation-and-execution)
- [Project Structure](#project-structure)
- [Tests](#run-tests)

## Prerequisites

- **CMake**: Make sure you have CMake installed (version 3.10 or higher).

## Installation

To install the project, download the repository and navigate to the project folder in the terminal.

## Compilation and Execution

To compile the project, use the following commands:

```bash
cmake -S . -B build
cmake --build build
cd build
./convert <command> <string>
```

### Commands

- **up**: Converts all letters in the string to uppercase.
- **down**: Converts all letters in the string to lowercase.
- **extract**: Extracts a substring from the given string based on specific criteria.
- **append**: Appends a string to the end of the original string.
- **insert**: Inserts a string at a specified position in the original string.
- **replace**: Replaces a part of the string with another string.
- **delete**: Deletes a portion of the string based on given parameters.

### Run Tests

The project contains unit tests in the `test` directory. To compile and run the tests:

```bash
cmake -S . -B build
cmake --build build
cd build
./ctest
```

## Project Structure

```plaintext
.
├── src
│   ├── StringConverter.cpp       # Implementation of string conversion functions
│   ├── main.cpp                  # Main program file
├── include
│   ├── StringConverter.hpp       # Header file with function declarations
│   ├── StringConverterTest.hpp   # Header file with test function declarations
├── test
│   ├── main_test.cpp             # Main test file
│   ├── StringConverterTest.cpp   # Test implementations
│   ├── CMakeLists.txt            # Test CMake configuration file
├── CMakeLists.txt                # Main CMake configuration file
└── README.md                     # Project documentation
```
