/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:09:53 by antoda-s          #+#    #+#             */
/*   Updated: 2024/11/14 10:35:38 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"
#include <stdlib.h>

void header(void)
{
	std::cout << " ██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗\n"
			  << " ██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝ \n"
			  << " ██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝ \n"
			  << " ██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗ \n"
			  << " ██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗ \n"
			  << " ╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝ \n"
			  << std::endl;

}

int main(void)
{
	system("clear");
	header();
	PhoneBook	pb;
	std::string	input;

	pb = PhoneBook();
	while (1)
	{
		pb._displayMenu();
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		else
		if (!input.compare("ADD"))
		// if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "REMOVE")
		{
			std::string removeInput;
			std::cout << "Enter index or phone number to remove: ";
			std::getline(std::cin, removeInput);
			if (isdigit(removeInput[0]))
				pb.remove(std::stoi(removeInput));
			else
				pb.remove(removeInput);
		}
		else if (input == "BOOKMARK")
		{
			std::string bookmarkInput;
			std::cout << "Enter index to bookmark: ";
			std::getline(std::cin, bookmarkInput);
			pb.bookmark(std::stoi(bookmarkInput));
		}
		else if (input == "EXIT")
			break;
		 else
			pb._displayInvalid();
	}
}
