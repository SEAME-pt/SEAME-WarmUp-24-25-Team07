/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringConverterTest.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 03:46:31 by nmoreira          #+#    #+#             */
/*   Updated: 2024/11/12 03:46:31 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/StringConverterTest.hpp"

StringConverterTest::StringConverterTest() {
	return ;
}


StringConverterTest::~StringConverterTest() {
	return ;
}


std::string StringConverterTest::test_to_upper(std::string &str) {
        return to_upper(str);
}


std::string StringConverterTest::test_to_lower(std::string &str) {
	return to_lower(str);
}


std::string StringConverterTest::test_extract(std::string &str, int start, int end) {
	return extract(str, start, end);
}


std::string StringConverterTest::test_append(std::string &str, std::string &str1) {
	return do_append(str, str1);
}


std::string StringConverterTest::test_insert(std::string &str, std::string &str1, int index) {
	return do_insert(str, str1, index);
}


std::string StringConverterTest::test_replace(std::string &str, std::string &str1, std::string &str2) {
	return do_replace(str, str1, str2);
}


std::string StringConverterTest::test_erase(std::string &str, std::string &str1) {
	return do_erase(str, str1);
}