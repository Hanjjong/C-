#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){}

ScavTrap::ScavTrap(const ScavTrap& origin)
{
    (*this) = origin;
    std::cout << "ScavTrap " << name << "이 복사 생성자로 생성되었습니다." << std::endl;
    return ;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
    if (this != &obj)
	{
		this->name = obj.name;
        this->attackDamage = obj.attackDamage;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        std::cout << "ScavTrap " << name << "이 복사대입 연산자를 호출하였습니다." << std::endl;
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap " << name << "이 파괴되었습니다." << std::endl; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap " << name << "이 생성되었습니다." << std::endl; 
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << name << " is now in Gatekeeper mode." << std::endl;
}