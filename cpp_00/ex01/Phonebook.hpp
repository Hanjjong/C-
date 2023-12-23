#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class	PhoneBook
{
private:
  Contact	contacts[8];
  int		index;

public:
    PhoneBook();
    ~PhoneBook();
    void add_contact();
    void print_contact();
};


#endif