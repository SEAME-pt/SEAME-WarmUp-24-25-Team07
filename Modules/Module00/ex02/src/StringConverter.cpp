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



std::string StringConverter::_to_upper(std::string &str) {
	// std::cout << "teste" << std::endl;
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << "Uppercase string: " << str;

	return str;
}


std::string StringConverter::_to_lower(std::string &str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	std::cout << "Lowercase string: " << str << std::endl;
	return str;
}


std::string StringConverter::_substr(std::string &str) {
	
	std::stringstream number;
	std::stringstream number1;
	int start;
	int end;
	std::string str1;
	std::string str2;
	std::string extract;

	while (str1.empty() && str2.empty()) {
        // (void) system("clear");
		int ret = system("clear"); //comentar para testes usar sem clear
		// int ret = system("");
		if (ret != 0) {
        	std::cerr << "Erro ao executar o comando 'clear'. Código de erro: " << ret << std::endl;
			extract = "";
			break;
    	}
		
        std::cout << "Extract string, index to START extraction: ";
        std::getline(std::cin, str1);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			extract = "";
            break;
        }

		number.str(str1);
		
		if (!(number >> start)) {

			std::cout << "Invalid input. Not a number!" << std::endl;
			extract = "";
			break;
		}
		if (start < 0) {
			std::cout << "Invalid input. Index must be a positive number!" << std::endl;
			extract = "";
			break;
		}
		// Faz a verificação se existem chars que não são numeros na string (ex: "123abc")
		if (!number.eof()) {
			std::cout << "Invalid input. Contains non-numeric characters!" << std::endl;
			extract = "";
			break;
		}

		std::cout << "Extract string, index to END extraction: ";
        std::getline(std::cin, str2);

		number1.str(str2);
		
		if (!(number1 >> end)) {
			std::cout << "Invalid input. Not a number!" << std::endl;
			extract = "";
			break;
		}

		if (end < 0) {
			std::cout << "Invalid input. Index must be a positive number!" << std::endl;
			extract = "";
			break;
		}
		// Faz a verificação se existem chars que não são numeros na string (ex: "123abc")
		if (!number1.eof()) {
			std::cout << "Invalid input. Contains non-numeric characters!" << std::endl;
			extract = "";
			break;
		}

		if (end <= start) {
			std::cout << "Invalid input. Index end must be higher then start!" << std::endl;
			extract = "";
			break;
		}

	    extract = str.substr(start, end - start);
     
        std::cout << "String extracted: " << extract << std::endl;
		break;
    }
	return extract;
}


std::string StringConverter::_append(std::string &str) {

	std::string str1;
	std::string result;

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
            break;
        }

	    result = str.append(str1);
     
        std::cout << "Output after append:" << result << std::endl;
		break;
    }
	return result;
}


std::string StringConverter::_insert(std::string &str) {
	
	std::string str1;
	std::string str2;
	std::string result;
	std::stringstream number;
	int index;

	while (str1.empty()) {
        // (void) system("clear");
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

		std::cout << std::endl;
		std::cout << "Index to insert string (starts from 0): ";
        std::getline(std::cin, str2);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			result = "";
            break;
        }

		number.str(str2);
		
		if (!(number >> index)) {
			std::cout << "Invalid input. Not a number!" << std::endl;
			result = "";
			break;
		}
		if (index < 0) {
			std::cout << "Invalid input. Index must be a positive number!" << std::endl;
			result = "";
			break;
		}
		// Faz a verificação se existem chars que não são numeros na string (ex: "123abc")
		if (!number.eof()) {
			std::cout << "Invalid input. Contains non-numeric characters!" << std::endl;
			result = "";
			break;
		}

	    result = str.insert(index, str1);
     
        std::cout << "Output after insert:" << result << std::endl;
		break;
    }

	return result;
}

std::string StringConverter::_replace(std::string &str) {
	
	std::string str1;
	std::string str2;
	std::string result;

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

		size_t pos = str.find(str1);
		if (pos == std::string::npos || str1.empty()) {
            std::cout << "Invalid input or string not found." << std::endl;
			result = "";
        	break;
        }


		std::cout << std::endl;
		std::cout << "Replacement string: ";
        std::getline(std::cin, str2);

        if (std::cin.eof() || std::cin.fail()) {
            std::cout << "\nInput ended." << std::endl;
			result = "";
            break;
        }

        while (pos != std::string::npos) {
            str.replace(pos, str1.size(), str2);
            pos = str.find(str1, pos + str2.size());
        }

		result = str;

        std::cout << "Output after replace:" << result << std::endl;
		break;
    }

	return result;
}



std::string StringConverter::_erase(std::string &str) {

    std::string str1;
    std::string result;

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

        size_t pos = str.find(str1);

        if (pos == std::string::npos || str1.empty()) {
            std::cout << "Invalid input or string not found." << std::endl;
			result = "";
        	break;
        }

        // Remover todas as ocorrências de str1 em str
        while (pos != std::string::npos) {
            str.erase(pos, str1.length());
            pos = str.find(str1); // procurar a próxima str
        }

		result = str;

        std::cout << "Output after erase:" << result << std::endl;
		break;
    }
	return result;
}



bool StringConverter::_ft_isspace(std::string s) const
{
    for (std::string::size_type i = 0; i < s.length(); i++)
    {
        if (!std::isspace(s[i]))
            return (false);
    }
    return (true);
}

std::string StringConverter::_trimString(std::string str)
{
	int i = 0;
	int start = 0;

	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	start = i;
	return (str.substr(start, str.length() - start));
}

bool StringConverter::_isSpecialCharacter(std::string str)
{
	for (int i = 0; i < (int)str.length() ; i++)
	{
		if (!(std::isalnum(str[i]) || str[i] == ' '))
			return 1;
	}
	return 0;
}



std::string StringConverter::convert(std::string level, std::string &str)
{
	// std::string info[7] = {"up", "down", "substr", "append", "insert", "replace", "erase"};
	std::string result;
	std::string info[7] = {"up", "down", "extract", "append", "insert", "replace", "erase"};

	std::string	(StringConverter:: *f[7])(std::string &str) = {&StringConverter::_to_upper, &StringConverter::_to_lower, &StringConverter::_substr, &StringConverter::_append, &StringConverter::_insert, &StringConverter::_replace, &StringConverter::_erase};
	for (int i = 0; i < 7; i++)
	{
		if (level == info[i])
			result = (this->*f[i])(str);
	}
	return result;
}
