#include "HumanB.hpp"

void    HumanB::attack()
{
    std::cout << name << "attacks with " << weapon->getType() << std::endl;
}
HumanB::HumanB(std::string name) : name(name){}

HumanB::~HumanB(){}

void    HumanB::setWeapon(Weapon &weapon){
    this->weapon = &weapon;
} 
