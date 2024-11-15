/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringConverterTest.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 03:46:48 by nmoreira          #+#    #+#             */
/*   Updated: 2024/11/12 03:46:48 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRINGCONVERTERTEST_HPP
#define STRINGCONVERTERTEST_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include "StringConverter.hpp"

class StringConverterTest: public StringConverter
{

	public:
		StringConverterTest();
		~StringConverterTest();
		
		std::string test_to_upper(std::string &str);
		std::string test_to_lower(std::string &str);
		std::string test_extract(std::string &str, int start, int end);
		std::string test_append(std::string &str, std::string &str1);
		std::string test_insert(std::string &str, std::string &str1, int index);
		std::string test_replace(std::string &str, std::string &str1, std::string &str2);
		std::string test_erase(std::string &str, std::string &str1);
};

#endif