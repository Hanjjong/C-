#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"


class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        Ice(const Ice& origin);
        const Ice& operator=(const Ice& obj);
        AMateria* clone() const;
        // void use(ICharacter& target);


};

#endif
