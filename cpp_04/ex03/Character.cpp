#include "Character.hpp"

Character::Character()
{
    // std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name) : name(name)
{
	// std::cout << "Character " << name << " constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::~Character()
{
    // std::cout << "Character descontructor called" << std::endl;
	for (int i = 0; i < 4; i++)
    {
		if (this->inventory[i])
			delete this->inventory[i];
    }
}

Character::Character(const Character &origin)
{
    (*this) = origin;
}

Character &Character::operator=(const Character &obj)
{
    if (this != &obj)
    {
        this->name = obj.name;
        for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = obj.inventory[i];
		}
    }
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria *m)
{
    for(int i = 0; i < 4; i++)
    {
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return ;
		}
    }
}

void Character::unequip(int idx)
{
    for (int i = 0; i < 4; i++)
    {
		if (i == idx && this->inventory[i])
			this->inventory[i] = 0;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (inventory[idx])
        inventory[idx]->use(target);
}
