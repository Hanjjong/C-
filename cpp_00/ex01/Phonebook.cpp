#include "Phonebook.hpp"
# include <cstdlib>

PhoneBook::PhoneBook() {
    // 생성자의 구현 내용
}

PhoneBook::~PhoneBook() {
    // 소멸자의 구현 내용
}


void PhoneBook::add_contact()
{
    this->contacts[index % 8].addcontact();
    this->index++;
}

void PhoneBook::print_contact()
{
    int i;
    std::string number;
    int num;

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
        std::cout << "enter number you want" << std::endl;
        std::getline(std::cin, number);
        if (std::cin.fail())
        {
            std::cout << "number error" << std::endl;
            std::cin.clear();
            std::cin.ignore(255, '\n');
            return ;
        }
        num = atoi(number.c_str());
        num = num - 1;
        if (num <= 7 && num >= 0 && num < this->index)
            this->contacts[num].show_contact();
        else
            std::cout << "out of range" << std::endl;
    }
}