#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

# define CLEAR_SCREEN "\033[2J\033[H"

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        Contact(std::string firstName, std::string lastName, std::string phoneNumber);
        void displayContact(void);

        std::string getName(void);
        std::string getLastName(void);
        std::string getNickName(void);
		std::string getPhoneNumber(void);

        static std::string formatField(std::string field);

        void setBookmarked(bool);
        bool isBookmarked();

    private:
        std::string _name;
        std::string _nickName;
        std::string _phoneNumber;
        bool _isBookmarked;
};

#endif