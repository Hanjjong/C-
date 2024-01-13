#include "HumanB.hpp"

void    HumanB::attack()
{
    if (this->weapon == NULL)
    {
        std::cout << "weapon is not setting" << weapon << std::endl;
        // return ;
    }
    std::cout << name << "attacks with " << weapon->getType() << std::endl;
}
HumanB::HumanB(std::string name) {
    this->name = name;
    // weapon = NULL;
}

HumanB::HumanB(){
    return;
}

HumanB::~HumanB(){}

void    HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
} 
