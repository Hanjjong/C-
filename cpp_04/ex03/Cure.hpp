#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(const Cure& origin);
        const Cure& operator=(const Cure& obj);
        AMateria* clone() const;
        // void use(ICharacter& target);
};

#endif
