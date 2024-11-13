/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 03:46:19 by nmoreira          #+#    #+#             */
/*   Updated: 2024/11/12 03:46:19 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cassert>
#include <iostream>
#include "../include/StringConverterTest.hpp"



void check_and_print(const std::string& test_name, const std::string& result, const std::string& expected) {
    std::cout << test_name << " - Resultado: " << result << ", Esperado: " << expected << std::endl;
    assert(result == expected && ("Erro no " + test_name).c_str());
}



int main() {
    StringConverterTest test;

    std::string str1 = "test";
    std::string str2 = "HELLO";
    std::string str3 = "example";

   
    std::string result = test.test_to_upper(str1);
    check_and_print("to_upper", result, "TEST");

   
    result = test.test_to_lower(str2);
    check_and_print("to_lower", result, "hello");

    
    result = test.test_append(str3, str1);
    check_and_print("do_append", result, "exampletest");

    str3 = "example";
    result = test.test_extract(str3, 0, 3);
    check_and_print("extract", result, "exa");

    
    // result = test.test_insert(str3, str1, 2);
    // check_and_print("do_insert", result, "extestample");

    
    std::string str4 = "hello world";
    std::string str5 = "world";
    std::string str6 = "universe";
    result = test.test_replace(str4, str5, str6);
    check_and_print("do_replace", result, "hello universe");

    str4 = "hello world";
	str6 = "world";
    result = test.test_erase(str4, str6);
    check_and_print("do_erase", result, "hello");
	

    std::cout << "Todos os testes passaram!" << std::endl;

    return 0;

}

