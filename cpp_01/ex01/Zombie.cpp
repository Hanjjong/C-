#include "Zombie.hpp"

Zombie::Zombie(){}


Zombie::~Zombie(){
    std::cout << name << " zombie deleted" << std::endl;
}

void    Zombie::announce()
{
    std::cout << "<" << name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}

