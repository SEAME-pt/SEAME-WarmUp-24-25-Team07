/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:56:57 by antoda-s          #+#    #+#             */
/*   Updated: 2024/11/14 12:23:46 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){ }

PhoneBook::~PhoneBook(void){ }

void PhoneBook::add(void)
{
	std::string name, nickname, pnumber;

	std::cout << "\n██████  PROVIDE CONTACT INFORMATION  ████████████████\n" << std::endl;
	std::cout << "Name    :  ";
	std::getline(std::cin, name, '\n');
	std::cout << "Phone number  :  ";
	std::getline(std::cin, pnumber, '\n');
	auto it = _contacts.find(pnumber);
    while (it != _contacts.end()) //! validate
    {
        std::cout << "\n██████  PHONE NUMBER ALREADY EXISTS  ████████████████\n" << std::endl;
		std::cout << "Phone number  :  ";
		if (!std::getline(std::cin, pnumber) || pnumber.empty())
        {
            std::cout << "\nInput error or EOF detected. Exiting...\n";
            return;
        }
		it = _contacts.find(pnumber);
    }
	std::cout << "Nickname      :  ";
	std::getline(std::cin, nickname, '\n');

	if (name.length() < 1 || nickname.length() < 1 || pnumber.length() < 1)
	{
		std::cout << "\n██████  A CONTACT CANT HAVE EMPTY FIELDS  ███████████\n" << std::endl;
		return ;
	}

	if (!_isStringPrintable(name) || !_isStringPrintable(nickname) 
		|| !_isStringPrintable(pnumber))
		{
			std::cout << "\n██████  INVALID CHARACTER INPUT  ██████████████████\n" << std::endl;
			return ;
		}
	Contact newContact(name, nickname, pnumber);
	this->_contacts.insert(std::make_pair(pnumber, new Contact(name, nickname, pnumber)));
	std::cout << "\n██████  CONTACT SAVED  ██████████████████████████████\n" << std::endl;
}

bool PhoneBook::_isStringPrintable(std::string str)
{
	for (size_t i=0; i < str.size(); i++)
		if (!isprint(str[i]))
			return false;
	return true;
}

void PhoneBook::_displayPhoneBook(void)
{
    const int CONTACTS_PER_PAGE = 9;
    int totalContacts = _contacts.size();
    int totalPages = (totalContacts + CONTACTS_PER_PAGE - 1) / CONTACTS_PER_PAGE;
    int currentPage = 0;

    while (true) {
        std::cout << "\n|     Index|First Name| Nickname| Phonenumber |" << std::endl;

        auto it = _contacts.begin();
        std::advance(it, currentPage * CONTACTS_PER_PAGE);

        for (int i = 0; i < CONTACTS_PER_PAGE && it != _contacts.end(); ++i, ++it) {
            std::cout << "|" << std::setw(10) << (currentPage * CONTACTS_PER_PAGE + i) << "|";
            std::string field = it->second->getName();
            std::cout << std::setw(10) << Contact::formatField(field) << "|";
            field = it->second->getNickName();
            std::cout << std::setw(10) << Contact::formatField(field) << "|";
            field = it->second->getPhoneNumber();
            std::cout << std::setw(10) << Contact::formatField(field) << "|" << std::endl;
        }

        std::cout << "\nPage " << (currentPage + 1) << " of " << totalPages << std::endl;
        std::cout << "Enter 'n' for next page, 'p' for previous page, 'q' to quit, or 's' to select a contact: ";
        char choice;
        if (!(std::cin >> choice)) {
            std::cout << "\nInput error or EOF detected. Exiting...\n";
            break;
        }
        if (choice == 'n' && currentPage < totalPages - 1) {
            currentPage++;
        } else if (choice == 'p' && currentPage > 0) {
            currentPage--;
        } else if (choice == 'q') {
            break;
        } else if (choice == 's') {
            std::cout << "Select id > ";
            int id;
            std::cin >> id;
            std::cin.ignore(1000, '\n');

            // Check for input that is not a number
            if (std::cin.fail()) {
                std::cout << "\n██████  INVALID INPUT  ██████████████████████████████\n" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            } else if (id < 0 || id >= totalContacts) {
                std::cout << "\n██████  NO CONTACT AT INDEX " << id << "  ██████████████████████\n" << std::endl;
            } else {
                auto it = _contacts.begin();
                std::advance(it, id);
                it->second->displayContact();
            }
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void PhoneBook::_displayPrompt(std::string prompt)
{
	std::cout << "\nPhonebook : " << prompt;
}

void PhoneBook::_displayMenu()
{
	std::cout << "██████  Phonebook Options  ██████████████████████████" << std::endl;
	std::cout << std::endl;
	std::cout << "        > ADD" << std::endl;
	std::cout << "        > SEARCH" << std::endl;
	std::cout << "        > REMOVE" << std::endl;
	std::cout << "        > BOOKMARK" << std::endl;
	std::cout << "        > EXIT" << std::endl;
	this->_displayPrompt("Enter your OPTION > ");
}

void PhoneBook::search(void)
{
    int id;
    int maxId = _contacts.size() - 1;

    // Display the phonebook table
    this->_displayPhoneBook();
    this->_displayPrompt("Select id > ");
    std::cin >> id;
    std::cin.ignore(1000, '\n');

    // Check for input that is not a number
    if (std::cin.fail())
    {
        std::cout << "\n██████  INVALID INPUT  ██████████████████████████████\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    else if (id < 0 || id > maxId)
    {
        std::cout << "\n██████  NO CONTACT AT INDEX " << id << "  ██████████████████████\n" << std::endl;
    }
    else
    {
        auto it = _contacts.begin();
        std::advance(it, id);
        it->second->displayContact();
    }
}

void PhoneBook::_displayInvalid()
{
	std::cout << "\n██████  INVALID INPUT  :  TRY AGAIN!  ███████████████\n" << std::endl;
}

void PhoneBook::remove(int index)
{
    if (index < 0 || index >= static_cast<int>(_contacts.size()))
    {
        std::cout << "\n██████  INVALID INDEX  ██████████████████████████████\n" << std::endl;
        return;
    }

    auto it = _contacts.begin();
    std::advance(it, index);
    _contacts.erase(it);
    std::cout << "\n██████  CONTACT REMOVED  ████████████████████████████\n" << std::endl;
}

size_t PhoneBook::getContactsSize() const
{
    return _contacts.size();
}

void PhoneBook::remove(const std::string& phoneNumber)
{
    auto it = std::find_if(_contacts.begin(), _contacts.end(),
                           [&phoneNumber](const auto& pair) {
                               return pair.first == phoneNumber;
                           });

    if (it != _contacts.end())
    {
        _contacts.erase(it);
        std::cout << "\n██████  CONTACT REMOVED  ████████████████████████████\n" << std::endl;
    }
    else
    {
        std::cout << "\n██████  CONTACT NOT FOUND  ██████████████████████████\n" << std::endl;
    }
}

void PhoneBook::bookmark(int index)
{
    if (index < 0 || index >= static_cast<int>(_contacts.size()))
    {
        std::cout << "\n██████  INVALID INDEX  ██████████████████████████████\n" << std::endl;
        return;
    }

    auto it = _contacts.begin();
    std::advance(it, index);
    it->second->setBookmarked(true);
    std::cout << "\n██████  CONTACT BOOKMARKED  █████████████████████████\n" << std::endl;
}

void PhoneBook::listBookmarks(void)
{
    std::cout << "\n|     Index|First Name| Nickname|  Phonenumber|" << std::endl;
    int index = 0;
    for (const auto& [key, contactPtr] : _contacts)
    {
        if (contactPtr->isBookmarked())
        {
            std::cout << "|" << std::setw(10) << index << "|";
            std::string field = contactPtr->getName();
            std::cout << std::setw(10) << Contact::formatField(field) << "|";
            field = contactPtr->getNickName();
            std::cout << std::setw(10) << Contact::formatField(field) << "|";
			field = contactPtr->getPhoneNumber();
            std::cout << std::setw(10) << Contact::formatField(field) << "|" << std::endl;
        }
        ++index;
    }
}
