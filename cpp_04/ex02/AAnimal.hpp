#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal{
    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(const AAnimal& origin);
        AAnimal& operator=(const AAnimal& obj);
        virtual ~AAnimal(void);
        virtual void makeSound(void) const = 0;
        const std::string& getType() const;
};

#endif