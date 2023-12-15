#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string p_number;
		std::string secret;
    std::string onlytenlength(std::string str);
    public:
        Contact();
        Contact(std::string firstname, std::string lastname, std::string nickname, std::string p_number, std::string secret);
        std::string get_firstname();
        std::string get_lastname();
        std::string get_nickname();
        std::string get_secret();
        void  print_contact();
        void  show_contact();
        void  addcontact();
        ~Contact();
};

#endif