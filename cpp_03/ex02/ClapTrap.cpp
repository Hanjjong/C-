#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(const std::string name) 
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "ClapTrap " << name << "이 생성되었습니다!" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << name << "이 파괴되었습니다!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& origin){
    (*this) = origin;
    std::cout << "ClapTrap " << name << "이 복사 생성자로 생성되었습니다." << std::endl;
    return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
    if (this != &obj)
	{
		this->name = obj.name;
        this->attackDamage = obj.attackDamage;
        this->hitPoints = obj.hitPoints;
        this->energyPoints = obj.energyPoints;
        std::cout << "ClapTrap " << name << "이 복사대입 연산자를 호출하였습니다." << std::endl;
	}
	return (*this);
}

int ClapTrap::getHitPoint(){
    return hitPoints;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints <= 0){
        std::cout << "체력(hit point)이 0입니다." << std::endl;
        return ;
    }
    if (energyPoints >= 1){
        std::cout << name << "이 " << target << "을(를) 공격하여 " << attackDamage << " 포인트의 피해를 입힙니다!" << std::endl;
        energyPoints--;
    }
    else {
        std::cout << "에너지 부족으로 공격할 수 없습니다." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    std::cout << name << "이 " << amount << " 포인트의 피해를 입었습니다!" << std::endl;
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (hitPoints <= 0){
        std::cout << "체력(hit point)이 0입니다." << std::endl;
        return ;
    }
    if (energyPoints >= 1){
        std::cout << name << "이 " << amount << " 포인트의 피해를 수리하여 체력이 회복되었습니다!" << std::endl;
        hitPoints += amount;
        energyPoints--;
    }
    else {
        std::cout << "에너지 부족으로 수리할 수 없습니다." << std::endl;
    }
}