#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain* brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog& origin);
        Dog& operator=(const Dog& obj);
        void makeSound(void) const;
        Brain* getBrain() const;
};

#endif