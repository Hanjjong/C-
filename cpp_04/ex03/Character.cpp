#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(){}

Character::Character(std::string name) : name(name)
{
	for(int i = 0; i < 4; i++)
		this->inventory[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
    {
		if (this->inventory[i])
			delete this->inventory[i];
    }
}

Character::Character(const Character &origin)
{
    for(int i = 0; i < 4; i++)
		this->inventory[i] = 0;
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
			this->inventory[i] = obj.inventory[i]->clone();
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
    if (idx >= 4)
        return ;
    if (this->inventory[idx])
    {
        inventory[idx]->use(target);
    }
}

AMateria* Character::getMateria(int idx) const
{
    if (inventory[idx])
        return inventory[idx];
    return 0;
}
