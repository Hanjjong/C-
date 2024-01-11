#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
    private:
        Brain* brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& origin);
        Cat& operator=(const Cat& obj);
        void makeSound(void) const;
};

#endif