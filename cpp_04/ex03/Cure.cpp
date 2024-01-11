#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &origin)
{
    (*this) = origin;
}

const Cure &Cure::operator=(const Cure &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
    // TODO: insert return statement here
}

AMateria *Cure::clone() const
{
    AMateria *p = new Cure();
	return p;
}

