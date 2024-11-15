/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:26:09 by nmoreira          #+#    #+#             */
/*   Updated: 2024/11/07 12:26:09 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/StringConverter.hpp"

StringConverter::StringConverter() {
	// std::cout << "Converting string..." << std::endl;
	return ;
}

StringConverter::~StringConverter() {
	// std::cout << "End." << std::endl;
	return ;
}



std::string StringConverter::to_upper(std::string &str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(), ::toupper);

	return result;
}


std::string StringConverter::to_lower(std::string &str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(), ::tolower);

	return result;
}


std::string StringConverter::extract(std::string &str, int start, int end) {
	
	std::string result;

	if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        // std::cout << "Invalid input. String is empty or contains only spaces!" << std::endl;
        result = "";
    } else if (start > str.length()) {
		result = "";
	} else if (start < 0 || end < 0) {
		// std::cout << "Invalid input. Indexes must be a positive number!" << std::endl;
		result = "";
	} else if (end <= start) {
		// std::cout << "Invalid input. Index end must be higher then start!" << std::endl;
		result = "";
	} else {
		result = str.substr(start, end - start);
	}

	return result;
}


std::string StringConverter::_substr(std::string &str) {
	
	std::stringstream number;
	std::stringstream number1;
	int start;
	int end;
	std::string str1;
	std::string str2;
	std::string result;

	if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        result = "";
		return result;
	}

	while (str1.empty()) {
       
		int ret = system("clear");
		if (ret != 0) {
        	std::cerr << "Erro ao executar o comando 'clear'. Código de erro: " << ret << std::endl;
			result = "";
			break;
    	}
		
        std::cout << "Extract string, index to START extraction (starts from 0): ";
        std::getline(std::cin, str1);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			result = "";
            break;
        }

		// Limpar a stream caso o utilizador faça enter sem nada
		number.clear();    
    	number.str("");

		number.str(str1);
		number >> start;
		
		// Faz a verificação se existem chars que não são numeros na string (ex: "123abc")
		if (!number.eof()) {
			std::cout << "Invalid input. Contains non-numeric characters!" << std::endl;
			result = "";
			break;
		}
	}

	while (str2.empty()) {

		int ret = system("clear");
		if (ret != 0) {
        	std::cerr << "Erro ao executar o comando 'clear'. Código de erro: " << ret << std::endl;
			result = "";
			break;
    	}

		std::cout << "Extract string, index to END extraction: ";
        std::getline(std::cin, str2);

		 if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			result = "";
            break;
        }

		// Limpar a stream caso o utilizador faça enter sem nada
		number1.clear();    
    	number1.str("");

		number1.str(str2);
		number1 >> end;

		// Faz a verificação se existem chars que não são numeros na string (ex: "123abc")
		if (!number1.eof()) {
			std::cout << "Invalid input. Contains non-numeric characters!" << std::endl;
			result = "";
			break;
		}

		result = extract(str, start, end);
		
    }

	return result;
}


std::string StringConverter::do_append(std::string &str, std::string &str1) {

	std::string result;

	
	if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        result = "";
	} else if (str1.empty() || str1.find_first_not_of(' ') == std::string::npos) {
		result = "";
	} else {
		result = str.append(str1);
	}

	return result;
}


std::string StringConverter::_append(std::string &str) {

	std::string str1;
	std::string result;

	if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        result = "";
		return result;
	}

	while (str1.empty()) {

        // int ret = system("clear");
		int ret = system("clear");
		if (ret != 0) {
        	std::cerr << "Erro ao executar o comando 'clear'. Código de erro: " << ret << std::endl;
			result = "";
			break;
    	}

        std::cout << "String to append: ";
        std::getline(std::cin, str1);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			result = "";
            break;
        }

	    result = do_append(str, str1);

    }
	return result;
}


std::string StringConverter::do_insert(std::string &str, std::string &str1, int index) {

	std::string result;

	if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        result = "";
		return result;
	}


	if (index < 0) {
		std::cout << "Invalid input. Index must be a positive number!" << std::endl;
		result = "";
	} else if (index > str.length()) {
		result = "";
	} else {
		result = str.insert(index, str1);
	}

	return result;
}


std::string StringConverter::_insert(std::string &str) {
	
	std::string str1;
	std::string str2;
	std::string result;
	std::stringstream number;
	int index;

	if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        result = "";
		return result;
	}

	while (str1.empty()) {

		int ret = system("clear");
		if (ret != 0) {
        	std::cerr << "Erro ao executar o comando 'clear'. Código de erro: " << ret << std::endl;
			result = "";
			break;
    	}

        std::cout << "String to insert: ";
        std::getline(std::cin, str1);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			result = "";
            break;
        }
	}

	while (str2.empty()) {

		int ret = system("clear");
		if (ret != 0) {
        	std::cerr << "Erro ao executar o comando 'clear'. Código de erro: " << ret << std::endl;
			result = "";
			break;
    	}

		std::cout << "Index to insert string (starts from 0): ";
        std::getline(std::cin, str2);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			result = "";
            break;
        }

		// Limpar a stream caso o utilizador faça enter sem nada
		number.clear();    
    	number.str("");

		number.str(str2);
		number >> index;
		
		// Faz a verificação se existem chars que não são numeros na string (ex: "123abc")
		if (!number.eof()) {
			std::cout << "Invalid input. Contains non-numeric characters!" << std::endl;
			result = "";
			break;
		}

	    result = do_insert(str, str1, index);
    }

	return result;
}


std::string StringConverter::do_replace(std::string &str, std::string &str1, std::string &str2) {

	std::string result;

	if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        result = "";
		return result;
	}

	size_t pos = str.find(str1);

	if (pos == std::string::npos || str1.empty()) {
		result = "";
	} else {
		result = str;
		while (pos != std::string::npos) {
            result.replace(pos, str1.size(), str2);
            pos = result.find(str1, pos + str2.size());
        }
	}

	return result;

}


std::string StringConverter::_replace(std::string &str) {
	
	std::string str1;
	std::string str2;
	std::string result;

	if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        result = "";
		return result;
	}

    while (str1.empty()) {

        int ret = system("clear");
		if (ret != 0) {
        	std::cerr << "Erro ao executar o comando 'clear'. Código de erro: " << ret << std::endl;
			result = "";
			break;
    	}
        std::cout << "String to replace: ";
        std::getline(std::cin, str1);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			result = "";
            break;
        }
	}

	while (str2.empty()) {

		int ret = system("clear");
		if (ret != 0) {
        	std::cerr << "Erro ao executar o comando 'clear'. Código de erro: " << ret << std::endl;
			result = "";
			break;
    	}

		std::cout << "Replacement string: ";
        std::getline(std::cin, str2);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			result = "";
            break;
        }

		result = do_replace(str, str1, str2);
		
    }

	return result;
}


std::string StringConverter::do_erase(std::string &str, std::string &str1) {

	std::string result;

	if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        result = "";
		return result;
	}

	size_t pos = str.find(str1);

	if (pos == std::string::npos || str1.empty()) {
		result = "";
	} else {
		result = str;
		while (pos != std::string::npos) {
            result.erase(pos, str1.length());
            pos = result.find(str1); // procurar a próxima str
        }
	}

	return result;

}


std::string StringConverter::_erase(std::string &str) {

    std::string str1;
    std::string result;

	if (str.empty() || str.find_first_not_of(' ') == std::string::npos) {
        result = "";
		return result;
	}

    while (str1.empty()) {
        // (void) system("clear");
		int ret = system("clear");
		if (ret != 0) {
        	std::cerr << "Erro ao executar o comando 'clear'. Código de erro: " << ret << std::endl;
			result = "";
			break;
    	}

        std::cout << "String to erase: ";
        std::getline(std::cin, str1);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			result = "";
            break;
        }

		result = do_erase(str, str1);

    }
	return result;
}



std::string StringConverter::convert(std::string level, std::string &str)
{
	std::string result;
	std::string info[7] = {"up", "down", "extract", "append", "insert", "replace", "delete"};

	std::string	(StringConverter:: *f[7])(std::string &str) = {&StringConverter::to_upper, &StringConverter::to_lower, &StringConverter::_substr, &StringConverter::_append, &StringConverter::_insert, &StringConverter::_replace, &StringConverter::_erase};
	for (int i = 0; i < 7; i++)
	{
		if (level == info[i])
			result = (this->*f[i])(str);
	}

	if (result.empty())
		result = "Invalid operation!! Try Again!!";

	return result;
}
