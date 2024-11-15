/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:50:54 by antoda-s          #+#    #+#             */
/*   Updated: 2024/11/14 14:37:09 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _isBookmarked(false) {}

Contact::~Contact(void) {}

Contact ::Contact(std::string fname, std::string nname, std::string pnumber)
{
	this->_name = fname;
	this->_nickName = nname;
	this->_phoneNumber = pnumber;
}

void Contact::displayContact(void)
{
	std::cout << std::endl;
	std::cout << "██████  Contact Information  ████████████████████████" << std::endl;
	std::cout << std::endl;
	std::cout << "  Name    :  \"" << this->_name << "\"" << std::endl;
	std::cout << "  Nickname      :  \"" << this->_nickName << "\"" << std::endl;
	std::cout << "  Phone Number  :  \"" << this->_phoneNumber << "\"" << std::endl;
	std::cout << "  Bookmark      :  \"" << (this->_isBookmarked ? "Yes" : "No") << "\"" << std::endl;
	std::cout << std::endl;
	char choice;
	std::cout << "Do you want to add or remove bookmark? (a/r) or (q to quit): ";
	std::cin >> choice;
	if (choice == 'a' || choice == 'A')
		this->setBookmarked(true);
	else if (choice == 'r' || choice == 'R')
		this->setBookmarked(false);
	else if (choice == 'q' || choice == 'Q')
	{
		std::cout << "Returning to previous menu." << std::endl;
		return;
	}
	else
		std::cout << "Invalid input. Returning to previous menu." << std::endl;
	std::cout << std::endl;
}

std::string Contact::formatField(std::string field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

std::string Contact::getName(void)
{
	return (this->_name);
}

std::string Contact::getNickName(void)
{
	return (this->_nickName);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

void Contact::setBookmarked(bool isBookmarked)
{
	this->_isBookmarked = isBookmarked;
}

bool Contact::isBookmarked()
{
	return this->_isBookmarked;
}
