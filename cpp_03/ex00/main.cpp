#include "ClapTrap.hpp"

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

    return 0;
}
