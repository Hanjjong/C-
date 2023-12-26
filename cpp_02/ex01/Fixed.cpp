#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    mvalue = 0;
}
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &origin){
    std::cout << "Copy constructor called" << std::endl;
    this->mvalue = origin.mvalue;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return mvalue;
}

void  Fixed::setRawBits(const int raw){
    mvalue = raw;
}

Fixed& Fixed::operator=(const Fixed& obj) 
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->mvalue = obj.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(int num){
    mvalue = num << mbit;
}
Fixed::Fixed(float num){
    this->mvalue = roundf(num *(1 << mbit)) ;
}

float	Fixed::toFloat(void) const
{
	return ((float)mvalue / (1 << mbit)); 
}
int	Fixed::toInt(void) const
{
	return (mvalue >> mbit);
}