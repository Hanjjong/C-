// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

void check_leaks(){
    system("do leaks animal");
}

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Animal* a = new Animal();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << a->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    a->makeSound();
    meta->makeSound();

    // WrongAnimal* parent = new WrongAnimal();
    WrongAnimal* cat = new WrongCat();
    WrongAnimal* animal = new WrongAnimal();
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