#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
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
}

AMateria *Cure::clone() const
{
    AMateria *p = new Cure();
	return p;
}

// void Cure::use(ICharacter &target)
// {
//     if (!this->getType().compare("cure"))
// 		std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
// }
