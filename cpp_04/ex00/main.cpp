// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    // WrongAnimal* parent = new WrongAnimal();
    WrongAnimal* animal = new WrongAnimal();
    WrongAnimal* cat = new WrongCat();
    std::cout << cat->getType() << std::endl;
    cat->makeSound();
    animal->makeSound();

    delete meta;
    delete i;
    delete j;
    delete cat;
    delete animal;

    return 0;
}