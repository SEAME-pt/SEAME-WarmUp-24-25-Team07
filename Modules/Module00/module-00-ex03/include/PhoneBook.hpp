/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:48:40 by antoda-s          #+#    #+#             */
/*   Updated: 2024/11/14 15:40:27 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <map>
# include <algorithm>

template<typename T>
T getInput(const std::string& prompt) {
    T input;
    std::cout << prompt + "    :  ";
    std::getline(std::cin, input);
    return input;
}
class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void add(std::string nm, std::string nn, std::string pn);
		void search(void);
		void receiveContact();
		void _displayMenu(void);
		void _displayPrompt(std::string prompt);
		void _displayPhoneBook(void);
		bool _isStringPrintable(std::string str);
		void _displayInvalid(void);
		size_t getContactsSize() const;

		void remove(int index);
		void remove(const std::string& phoneNumber);
		void bookmark(int index);
		void listBookmarks(void);

	private:
		std::multimap<std::string, Contact> _contacts;
	// private:
};

#endif
