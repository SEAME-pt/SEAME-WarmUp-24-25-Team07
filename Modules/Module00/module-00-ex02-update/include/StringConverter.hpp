/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:06:08 by nmoreira          #+#    #+#             */
/*   Updated: 2024/11/06 03:06:08 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRINGCONVERTER_HPP
#define STRINGCONVERTER_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class StringConverter
{
	private:
		std::string _to_upper( std::string &str );
		std::string _to_lower( std::string &str );
		std::string _substr( std::string &str );
		std::string _append( std::string &str );
		std::string _insert( std::string &str );
		std::string _replace( std::string &str );
		std::string _erase( std::string &str);
		std::string _trimString(std::string str);
		bool _isSpecialCharacter(std::string str);
		bool _ft_isspace(std::string s) const;

	public:
		StringConverter();
		~StringConverter();
		std::string convert(std::string level, std::string &str);
};

#endif