#include "Zombie.hpp"

int main()
{
    Zombie stackZombie("stack zombie1");
    Zombie* heapZombie = newZombie("heap zombie1");

    stackZombie.announce();
    heapZombie->announce();
    randomChump("stack zombie2");
    delete heapZombie;
    return 0;
}