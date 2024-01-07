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
    std::cout << "ScavTrap " << name << "이 생성되었습니다!" << std::endl; 
}

void ScavTrap::attack(const std::string& target)
{
    if (hitPoints <= 0){
        std::cout << "[ScavTrap] " << "체력(hit point)이 0입니다." << std::endl;
        return ;
    }
    if (energyPoints >= 1){
        std::cout << "[ScavTrap] " << name << "이 " << target << "을(를) 공격하여 " << attackDamage << " 포인트의 피해를 입힙니다!" << std::endl;
        energyPoints--;
    }
    else {
        std::cout << "[ScavTrap] " << "에너지 부족으로 공격할 수 없습니다." << std::endl;
    }
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << name << " is now in Gatekeeper mode." << std::endl;
}