#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    // ClapTrap claptrap("IRON MAN");

    FragTrap fragtrap("PAPER MAN");
    // claptrap.attack("적군 A");
    // std::cout << "체력" << claptrap.getHitPoint() << std::endl;
    fragtrap.takeDamage(9);
    //  std::cout << "체력" << claptrap.getHitPoint() << std::endl;
    fragtrap.beRepaired(20);
     std::cout << "체력" << fragtrap.getHitPoint() << std::endl;
    fragtrap.highFivesGuys();
    // std::cout << "체력" << copy.getHitPoint() << std::endl;
    return 0;
}
