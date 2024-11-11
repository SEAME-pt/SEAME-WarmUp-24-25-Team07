/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmoreira <nmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:18:17 by nmoreira          #+#    #+#             */
/*   Updated: 2024/11/07 10:18:17 by nmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/StringConverter.hpp"

int	main(int argc, char **argv)
{
	StringConverter	words;
	std::string str;
	std::string level;
	std::string result;

	if (argc != 3)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	level = argv[1];
	str = argv[2];
	result = words.convert(level, str);
	std::cout << result << std::endl;

	return 0;
}