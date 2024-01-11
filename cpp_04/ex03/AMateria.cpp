#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &origin)
{
    (*this) = origin;
    std::cout << "AMateria copy constructor called" << std::endl;
}

const AMateria &AMateria::operator=(const AMateria &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return (*this);
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "AMateria constructor called" << std::endl;

}

std::string const &AMateria::getType() const
{
   return (this->type);
}

void AMateria::use(ICharacter &target)
{
    if (!this->getType().compare("ice"))
		std::cout << "* shoots an ice bolt at "<< target.getName() << " *"<< std::endl;
	else if (!this->getType().compare("cure"))
		std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}
