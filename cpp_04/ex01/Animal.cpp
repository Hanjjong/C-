#include "Animal.hpp"

Animal::Animal(){
    this->type = "Animal";
    std::cout << "Animal이 생성되었습니다." << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal이 소멸되었습니다." << std::endl;
}

Animal::Animal(const Animal& origin){
    (*this) = origin;
    std::cout << "Animal " << "이 복사 생성자로 생성되었습니다." << std::endl;
    return ;
}

Animal& Animal::operator=(const Animal& obj)
{
    if (this != &obj)
        this->type = obj.type;
	return (*this);
}

void    Animal::makeSound() const {
    std::cout << "i'm animal" << std::endl;
}

const std::string& Animal::getType() const {
    return (this->type);
} 
