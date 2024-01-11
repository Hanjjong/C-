#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog"; 
    std::cout << "Dog이 생성되었습니다." << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog이 소멸되었습니다." << std::endl;
}

Dog::Dog(const Dog &origin)
{
    (*this) = origin;
    std::cout << "Dog " << "이 복사 생성자로 생성되었습니다." << std::endl;
    return ;
}

Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
    {
        this->type = type;
    }
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "bow wow" << std::endl;
}

