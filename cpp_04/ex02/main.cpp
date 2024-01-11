// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
    AAnimal* animals[10];

    for(int i = 0; i < 10; i++)
    {
        std::cout << i << " ";
        if (i < 5)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    for(int i = 0; i < 10; i++){
        animals[i]->makeSound();
    }
    for (int i = 0; i < 10; i++){
        std::cout << i << " ";
        delete animals[i];
    }
    
    Dog dog;
    Dog copyDog(dog);
    std::cout <<"------------------origin--------------" <<std::endl;
    std::cout << "dog==============================" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << dog.getBrain()->getIdea(i) << std::endl;
    std::cout <<"copy dog===============================" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << copyDog.getBrain()->getIdea(i) << std::endl;
    for (int i = 0; i < 10; i++){
        copyDog.getBrain()->setIdeas("change Idea" , i);
    }
    std::cout <<"-----------------change----------------" <<std::endl;
    std::cout <<"dog===============================" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << dog.getBrain()->getIdea(i) << std::endl;
    std::cout <<"copy dog===============================" << std::endl;
    for (int i = 0; i < 10; i++)
       std::cout << copyDog.getBrain()->getIdea(i) << std::endl;

    return 0;
}