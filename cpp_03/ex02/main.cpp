#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap claptrap("IRON MAN");

    claptrap.attack("적군 B");
    claptrap.takeDamage(9);
    claptrap.beRepaired(9);
    std::cout << "----체력" << claptrap.getHitPoint() << std::endl;
    claptrap.takeDamage(11);
    std::cout << "----체력" << claptrap.getHitPoint() << std::endl;
    claptrap.beRepaired(9);

    std::cout << "===============================================" << std::endl;
//------------------------------------------

    ScavTrap scavtrap("PAPER MAN");

    scavtrap.attack("적군 A");
    scavtrap.takeDamage(9);
    scavtrap.beRepaired(9);
    std::cout << "----체력" << scavtrap.getHitPoint() << std::endl;
    scavtrap.takeDamage(1000);
    std::cout << "----체력" << scavtrap.getHitPoint() << std::endl;
    scavtrap.attack("적군 A");
    scavtrap.beRepaired(9);
    scavtrap.guardGate();
//-------------------------------------------
    return 0;
}
