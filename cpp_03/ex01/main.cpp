#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    // ClapTrap claptrap("IRON MAN");

    ScavTrap scavtrap("PAPER MAN");
    // claptrap.attack("적군 A");
    // std::cout << "체력" << claptrap.getHitPoint() << std::endl;
    scavtrap.takeDamage(9);
    //  std::cout << "체력" << claptrap.getHitPoint() << std::endl;
    scavtrap.beRepaired(20);
     std::cout << "체력" << scavtrap.getHitPoint() << std::endl;
    
    // std::cout << "체력" << copy.getHitPoint() << std::endl;
    return 0;
}
