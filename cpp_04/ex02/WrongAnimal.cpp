#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
}

WrongAnimal::WrongAnimal(const WrongAnimal &origin)
{
    (*this) = origin;
    std::cout << "WrongAnimal " << "이 복사 생성자로 생성되었습니다." << std::endl;
    return ;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    if (this != &obj)
        this->type = obj.type;
	return (*this);
}

void WrongAnimal::makeSound()
{
    std::cout << "i'm wrong..... animal" << std::endl;
}

const std::string &WrongAnimal::getType() const
{
    return (this->type);
}
