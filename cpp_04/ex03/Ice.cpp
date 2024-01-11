#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(const Ice &origin)
{
    (*this) = origin;
}

const Ice &Ice::operator=(const Ice &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

AMateria *Ice::clone() const
{
    AMateria *p = new Ice();
	return p;
}

