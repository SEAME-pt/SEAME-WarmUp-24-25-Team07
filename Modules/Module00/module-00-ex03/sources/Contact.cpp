/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:50:54 by antoda-s          #+#    #+#             */
/*   Updated: 2024/09/23 11:39:18 by antoda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

Contact::Contact(void)
{

}

Contact::~Contact(void)
{

}

Contact :: Contact(std::string fname, std::string lname, std::string nname, std::string pnumber, std::string dsecret)
{
	this->_firstName = fname;
	this->_lastName = lname;
	this->_nickName = nname;
	this->_phoneNumber = pnumber;
	this->_darkestSecret = dsecret;
}

void Contact::displayContact(void)
{
	std::cout << std::endl;
	std::cout << "██████  Contact Information  ████████████████████████" << std::endl;
	std::cout << std::endl;
	std::cout << "  First name    :  \"" << this->_firstName << "\"" << std::endl;
	std::cout << "  Last name     :  \"" << this->_lastName << "\"" << std::endl;
	std::cout << "  Nickname      :  \"" << this->_nickName << "\"" << std::endl;
	std::cout << "  Phone Number  :  \"" << this->_phoneNumber << "\"" << std::endl;
	std::cout << "  Darkest Secret:  \"" << this->_darkestSecret << "\"" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

std::string Contact::formatField(std::string field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

std::string Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string Contact::getNickName(void)
{
	return (this->_nickName);
}