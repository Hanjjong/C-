#include "PhoneBook.hpp"
# include <cstdlib>

int main(void)
{
    PhoneBook phonebook;
    std::string cmd;

    while (1)
    {
        if (std::cin.eof() != 1)
            std::cout << "please enter command" << std::endl;
        std::getline(std::cin, cmd);
        if (std::cin.eof() == 1)
            return (0);
        if (cmd == "ADD")
        {
            phonebook.add_contact();
        }
        else if (cmd == "SEARCH")
        {
            phonebook.print_contact();
        }
        else if (cmd == "EXIT")
        {
            break ;
        }
        else
        {
            std::cout << "invalid command" << std::endl;
        }
    }
    return (0);
}