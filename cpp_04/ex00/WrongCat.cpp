#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat이 생성되었습니다." << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat이 생성되었습니다." << std::endl;
}


WrongCat::WrongCat(const WrongCat &origin) 
{
    (*this) = origin;
    std::cout << "WrongAnimal " << "이 복사 생성자로 생성되었습니다." << std::endl;
    return ;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    if (this != &obj)
        this->type = obj.type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "cat can't barking" << std::endl;
}
