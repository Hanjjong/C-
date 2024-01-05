#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(){}

FragTrap::~FragTrap(){
    std::cout << "ScavTrap " << name << "이 파괴되었습니다." << std::endl;
}

FragTrap::FragTrap(const FragTrap& origin)
{
    (*this) = origin;
    std::cout << "FragTrap " << name << "이 복사 생성자로 생성되었습니다." << std::endl;
    return ;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    if (this != &obj)
	{
		this->name = obj.name;
        this->attackDamage = obj.attackDamage;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        std::cout << "FragTrap " << name << "이 복사대입 연산자를 호출하였습니다." << std::endl;
	}
	return (*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "ScavTrap " << name << "이 생성되었습니다." << std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout << name << "HighFive!!!!!!!!" << std::endl;
}

