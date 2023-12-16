#include "Phonebook.hpp"
# include <cstdlib>

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
        std::cout 	<< "     index" << "|" 
					<< "first name" << "|" 
					<< " last name" << "|" 
					<< "  nickname" << "|" << std::endl;
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
                if (number.size() == 1 && number[0] <= '8' &&  number[0] >= '1' && (atoi(number.c_str()) - 1) < this->index)
                {
                    this->contacts[atoi(number.c_str()) - 1].show_contact();
                    break ;
                }
                else
                    std::cout << "invalid number" << std::endl;           
            }
        }
        return ;
    }
}