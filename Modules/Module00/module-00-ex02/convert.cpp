
#include "convert.hpp"

std::string convert_to_lowercase(const std::string &str) {
    std::string result = str;   
    for (char &c : result) {
        c = std::tolower(c);
    }
    return result;
}

std::string convert_to_uppercase(const std::string &str) {
    std::string result = str;   
    for (char &c : result) {
        c = std::toupper(c);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <command> <string>" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    std::string str = argv[2];

    if (str.empty() || command.empty()) {
        std::cerr << "Error: at least one of the args is empty" << std::endl;
        return 1;
    }

    if (command == "up") {
        std::cout << convert_to_uppercase(str) << std::endl;
    } else if (command == "down") {
        std::cout << convert_to_lowercase(str) << std::endl;
    } else {
        std::cerr << "Error: invalid command" << std::endl;
        return 1;
    }

    return 0;
}
