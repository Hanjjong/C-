#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"


class Character : public ICharacter
{
    private:
        std::string name;
        AMateria    *inventory[4];
    public:
        Character();
        ~Character();
        Character(std::string name);
        Character(const Character& origin); 
        Character& operator=(const Character& obj); //깊은 복사해야댐요
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

};

#endif