/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaral- <mamaral-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:48:40 by antoda-s          #+#    #+#             */
/*   Updated: 2024/11/14 10:34:55 by mamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

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

		void remove(int index);
		void remove(std::string phoneNumber);
		void bookmark(int index);
		void listBookmarks(void);

	private:
		int _i;
		static const int MAX_CONTACTS = 8;
		Contact _contacts[MAX_CONTACTS];

	// private:
};

#endif
