#include "PhoneBook.hpp"


void Contact::print_contact()
{
    std::cout << "|" << std::setw(10) << onlytenlength(this->firstname) 
                << "|" << std::setw(10) << onlytenlength(lastname) 
                << "|" << std::setw(10) << onlytenlength(nickname)  
                << "|" << std::endl;
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
        return (str);
}

int is_space(const char *str)
{
    int i = 0;
    while (str[i])
    {
        if (std::isspace(str[i]) == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void    Contact::setContact(std::string firstname, std::string lastname, std::string nickname, std::string p_number, std::string secret)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->nickname = nickname;
    this->p_number = p_number;
    this->secret = secret;
}

void Contact::addcontact()
{
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string p_number;
    std::string secret;

    while (!std::cin.eof())
    {
        std::cout << "His(her) first name is..." << std::endl;
        if (std::getline(std::cin, firstname))
        {
            if (is_space(firstname.c_str()) != 0)
                continue;
            else
                break ;
        }
    }
    while (!std::cin.eof())
    {
        std::cout << "His(her) last name is..." << std::endl;
        if (std::getline(std::cin, lastname))
        {
            if (is_space(lastname.c_str()) != 0)
                continue;
            else
                break ;
        }
    }
    while (!std::cin.eof())
    {
        std::cout << "His(her) nickname is..." << std::endl;
        if (std::getline(std::cin, nickname))
        {
            if (is_space(nickname.c_str()) != 0)
                continue;
            else
                break ;
        }
    }
    while (!std::cin.eof())
    {
        std::cout << "His(her) phone number is..." << std::endl;
        if (std::getline(std::cin, p_number))
        {
            if (is_space(p_number.c_str()) != 0)
                continue;
            else
                break ;
        }
    }
    while (!std::cin.eof())
    {
        std::cout << "His(her) darkest secret is..." << std::endl;
        if (std::getline(std::cin, secret))
        {
            if (is_space(secret.c_str()) != 0)
                continue;
            else
                break ;
        }
    }
    if (std::cin.eof())
        return ;
    setContact(firstname, lastname, nickname, p_number, secret);
	std::cout << "Save his(her) Contact." << std::endl;
}
