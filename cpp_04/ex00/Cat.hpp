#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& origin);
        Cat& operator=(const Cat& obj);
        void makeSound(void) const;
};

#endif