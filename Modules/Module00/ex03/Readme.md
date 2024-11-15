# Old PhoneBook

## Introduction
This project is a simple command-line phonebook application that allows users to manage contacts. The application supports adding, searching, removing, and bookmarking contacts. It is designed to run in a terminal environment and does not require any graphical interface.

## Features
- **Add Contact**: Add a new contact with a name, nickname, and phone number.
- **Search Contact**: List all contacts and display details of a selected contact.
- **Remove Contact**: Remove a contact by index or phone number.
- **Bookmark Contact**: Bookmark a contact for quick access.
- **List Bookmarks**: List all bookmarked contacts.
- **Exit**: Exit the application.

## Usage
To use the phonebook application, run the executable and follow the on-screen prompts to manage your contacts.

### Commands
- `ADD`: Add a new contact.
- `SEARCH`: Search and display contacts.
- `REMOVE`: Remove a contact by index or phone number.
- `BOOKMARK`: List all bookmarked contacts.
- `EXIT`: Exit the application.

## Building the Project
To build the project, you can use either CMake or qmake.

### Using CMake
1. Navigate to the project directory:
    ```sh
    cd Modules/Module00/ex03
    ```
2. Create a build directory and navigate into it:
    ```sh
    mkdir build && cd build
    ```
3. Run CMake to configure the project:
    ```sh
    cmake ..
    ```
4. Build the project:
    ```sh
    make
    ```

### Using qmake
1. Navigate to the project directory:
    ```sh
    cd Modules/Module00/ex03
    ```
2. Run qmake to generate the Makefile:
    ```sh
    qmake module-00-ex03.pro
    ```
3. Build the project:
    ```sh
    make
    ```

## Running Tests
The project includes unit tests using Catch2. To run the tests, follow these steps:

1. Build the tests:
    ```sh
    cd Modules/Module00/ex03/build
    make tests
    ```
2. Run the tests:
    ```sh
    ./tests
    ```

## Project Structure
```
.
├── LICENSE
├── Modules
│   ├── Module00
│   │   └── ex03
│   │       ├── CMakeLists.txt
│   │       ├── include
│   │       │   ├── Contact.hpp
│   │       │   └── PhoneBook.hpp
│   │       ├── module-00-ex03.pro
│	│		├── README.md
│   │       ├── sources
│   │       │   ├── Contact.cpp
│   │       │   ├── PhoneBook.cpp
│   │       │   └── main.cpp
│   │       └── tests
│   │           ├── CMakeLists.txt
│   │           └── test_phonebook.cpp
│   └── Module00.md
└── README.md



```

## License
This project is licensed under the terms of the [Creative Commons Legal Code](LICENSE).

## Contributing
Contributions are welcome! Please follow the standard GitHub workflow for contributing to this project:
1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Commit your changes.
4. Push the branch to your fork.
5. Create a pull request.

## Issue Tracking
For any issues or feature requests, please use the [GitHub Issues](https://github.com/your-repo/issues) page.

## Contact
For any questions or inquiries, please contact the project maintainers at
[afmyhouse](https://github.com/afmyhouse)  
[HeitorMP](https://github.com/HeitorMP)  
[nunotaboada](https://github.com/nunotaboada)  
[MicchelFAB](https://github.com/MicchelFAB)