#include "AAnimal.hpp"

AAnimal::AAnimal(){
    this->type = "Animal";
    std::cout << "Animal이 생성되었습니다." << std::endl;
}

AAnimal::~AAnimal(){
    std::cout << "Animal이 소멸되었습니다." << std::endl;
}

AAnimal::AAnimal(const AAnimal& origin){
    (*this) = origin;
    std::cout << "Animal " << "이 복사 생성자로 생성되었습니다." << std::endl;
    return ;
}

AAnimal& AAnimal::operator=(const AAnimal& obj)
{
    if (this != &obj)
        this->type = obj.type;
	return (*this);
}

void    AAnimal::makeSound() const {
    std::cout << "i'm animal" << std::endl;
}

const std::string& AAnimal::getType() const {
    return (this->type);
} 
