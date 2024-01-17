#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MaterialSource.hpp"

int main()
{
    MateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    return 0;

    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");

    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob);
    // me->use(1, *bob);

    // // delete tmp;
    // delete me;

    // // ------------------

    // Character* me2 = new Character("me");

    // AMateria* tmp2;
    // tmp2 = src->createMateria("ice");
    // me2->equip(tmp2);
    // tmp2 = src->createMateria("cure");
    // me2->equip(tmp2);

    // me2->use(0, *bob);
    // me2->use(1, *bob);

    // AMateria* floor;
    // floor = me2->getMateria(0);
    // me2->unequip(0);
    // delete floor;
    // floor = me2->getMateria(1);
    // me2->unequip(1);
    // delete floor;

    // // delete tmp2;
    // delete bob;
    // delete me2;
    // delete src;

    // atexit(check_leaks);
    // return 0;
}