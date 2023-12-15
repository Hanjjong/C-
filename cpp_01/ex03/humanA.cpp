#include "humanA.hpp"

void    HumanA::attack()
{
    std::cout << name << "attacks with " << weapon.getType() << std::endl;
}
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){}

HumanA::~HumanA(){}
