#include "Zombie.hpp"


Zombie::~Zombie(){
    std::cout << name << " zombie deleted" << std::endl;
}

Zombie::Zombie(std::string name){
    this->name = name;
}

void    Zombie::announce()
{
    std::cout << "<" << name << ">" << " BraiiiiiiinnnzzzZ..." << std::endl;
}
