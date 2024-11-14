/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 20:09:53 by antoda-s          #+#    #+#             */
/*   Updated: 2024/11/14 12:24:47 by mamaral-         ###   ########.fr       */
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
			pb._displayPhoneBook();
		else if (input == "REMOVE")
		{
			std::string removeInput;
			std::cout << "Enter index or phone number to remove: ";
			std::getline(std::cin, removeInput);

			// Check if the input is a number
			if (!removeInput.empty() && std::all_of(removeInput.begin(), removeInput.end(), ::isdigit))
			{
				int index = std::stoi(removeInput);
				if (index >= 0 && index < static_cast<int>(pb.getContactsSize())) // Assuming getContactsSize() returns the size of the contacts
				{
					pb.remove(index);
				}
				else
				{
					pb.remove(removeInput); // Treat as phone number if index is out of range
				}
			}
			else
			{
				pb.remove(removeInput);
			}
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
