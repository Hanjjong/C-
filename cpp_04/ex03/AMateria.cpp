#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("Unknown")
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &origin)
{
    (*this) = origin;
}

const AMateria &AMateria::operator=(const AMateria &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

AMateria::AMateria(std::string const &type) : type(type) {}

std::string const &AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}
