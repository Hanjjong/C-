#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MaterialSource.hpp"

void check_leaks()
{
    system("leaks Materia");
}

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    // me->unequip(0);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // tmp = src->createMateria("ice");
    // me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    // me->use(2, *bob);
    // me->use(3, *bob);
    // me->use(4, *bob);
    delete bob;
    delete me;
    delete src;
    atexit(check_leaks);
    return 0;
}