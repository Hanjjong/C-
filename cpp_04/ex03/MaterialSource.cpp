#include "MaterialSource.hpp"

MateriaSource::MateriaSource()
{
    // std::cout << "MateriaSource Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->slot[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& origin)
{
    for(int i = 0; i < 4; i++)
		this->slot[i] = 0;
    // std::cout << "MateriaSource Copy constructor called" << std::endl;
	(*this) = origin;
}

MateriaSource& MateriaSource::operator=(const MateriaSource  &obj)
{
    if (this != &obj)
    {
        for (int i = 0; i < 4; i++)
		{
			if (this->slot[i])
				delete this->slot[i];
			this->slot[i] = obj.slot[i];
		}
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i])
            delete this->slot[i];
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->slot[i])
        {
            this->slot[i] = m;
            return ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->slot[i] && !this->slot[i]->getType().compare(type))
            return this->slot[i]->clone();
    }
    return 0;
}
