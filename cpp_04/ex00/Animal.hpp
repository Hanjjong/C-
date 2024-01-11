#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal& origin);
        Animal& operator=(const Animal& obj);
        virtual ~Animal(void);
        virtual void makeSound(void) const;
        const std::string& getType() const;
};

#endif