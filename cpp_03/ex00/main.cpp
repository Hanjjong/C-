#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap("IRON MAN");

    claptrap.attack("적군 A");
    // std::cout << "체력" << claptrap.getHitPoint() << std::endl;
    claptrap.takeDamage(9);
    //  std::cout << "체력" << claptrap.getHitPoint() << std::endl;
    claptrap.beRepaired(20);
    //  std::cout << "체력" << claptrap.getHitPoint() << std::endl;
    
    ClapTrap copy(claptrap);
    // std::cout << "체력" << copy.getHitPoint() << std::endl;
    return 0;
}
