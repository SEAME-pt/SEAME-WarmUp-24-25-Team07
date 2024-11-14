/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:48:40 by antoda-s          #+#    #+#             */
/*   Updated: 2024/11/14 12:19:10 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <map>
# include <algorithm>

struct ContactKey {
    std::string name;
    std::string number;

    bool operator<(const ContactKey& other) const;

};
class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void add(void);
		void search(void);
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
		std::multimap<std::string, Contact*> _contacts;
	// private:
};

#endif
