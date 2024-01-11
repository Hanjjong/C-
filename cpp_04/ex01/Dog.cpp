#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog"; 
    this->brain = new Brain();
    std::cout << "Dog이 생성되었습니다." << std::endl;
}

Dog::~Dog(){
    delete this->brain;
    std::cout << "Dog이 소멸되었습니다." << std::endl;
}

Dog::Dog(const Dog &origin) : brain(new Brain())
{
    (*this) = origin;
    std::cout << "Dog " << "이 복사 생성자로 생성되었습니다." << std::endl;
    return ;
}

Dog &Dog::operator=(const Dog &obj)
{
     if (this != &obj)
    {
        this->type = obj.type;
        delete this->brain;
        this->brain = new Brain(*obj.brain);
    }
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "bow wow" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}