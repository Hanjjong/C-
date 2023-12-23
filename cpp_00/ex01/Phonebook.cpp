#include "PhoneBook.hpp"
// # include <cstdlib>

PhoneBook::PhoneBook() {
    index = 0;
}

PhoneBook::~PhoneBook() {}


void PhoneBook::add_contact()
{
    this->contacts[index % 8].addcontact();
    this->index++;
}

void PhoneBook::print_contact()
{
    int i;
    std::string number;

    i = 0;
    if (this->index == 0)
    {
        std::cout << "contact isn't exist" << std::endl;
        return ;
    }
    else 
    {
        std::cout 	<< std::setw(10) << "index" << "|" 
					<< std::setw(10) << "first name" << "|" 
					<< std::setw(10) << "last name" << "|" 
					<< std::setw(10) << "nickname" << "|" << std::endl;
        while (i < this->index && i < 8)
        {
            std::cout << "         " << i + 1;
            this->contacts[i].print_contact();
            i++;
        }
        while(!std::cin.eof())
        {
            std::cout << "enter number you want" << std::endl;
            if (std::getline(std::cin, number))
            {
                int num = std::atoi(number.c_str());
                if (number.size() == 1 && num <= 8 &&  num >= 1 && num - 1 < this->index)
                {
                    this->contacts[num - 1].show_contact();
                    break ;
                }
                else
                    std::cout << "invalid number" << std::endl;           
            }
        }
        return ;
    }
}