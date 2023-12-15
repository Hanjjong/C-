#include "Phonebook.hpp"

Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string p_number, std::string secret)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->nickname = nickname;
    this->p_number = p_number;
    this->secret = secret;
}

std::string Contact::get_firstname()
{
    return (this->firstname);
}

std::string Contact::get_lastname()
{
    return (this->lastname);
}

std::string Contact::get_nickname()
{
    return (this->nickname);
}

std::string Contact::get_secret()
{
    return (this->secret);
}

void Contact::print_contact()
{
    std::cout << "|" << onlytenlength(this->firstname) << "|" << onlytenlength(lastname) << "|" << onlytenlength(nickname) << std::endl;
}

Contact::Contact()
{

}
Contact::~Contact()
{
    
}

void Contact::show_contact()
{
    std::cout << "firstname : " << this->firstname << std::endl;
    std::cout << "lastname : " << this->lastname << std::endl;
    std::cout << "nickname : " << this->nickname << std::endl;
    std::cout << "p_number : " << this->p_number << std::endl;
    std::cout << "secret : " << this->secret << std::endl;
}

std::string Contact::onlytenlength(std::string str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (std::string(10 - str.size(), ' ') + str);
}

void Contact::addcontact()
{
    std::cout << "His(her) first name is..." << std::endl;
    std::getline(std::cin, this->firstname);
	std::cout << "His(her) last name is..." << std::endl;
    std::getline(std::cin, this->lastname);
	std::cout << "His(her) nickname is..." << std::endl;
    std::getline(std::cin, this->nickname);
	std::cout << "His(her) phone number is..." << std::endl;
    std::getline(std::cin, this->p_number);
	std::cout << "His(her) darkest secret is..." << std::endl;
    std::getline(std::cin, this->secret);
	std::cout << "Save his(her) Contact." << std::endl;
}