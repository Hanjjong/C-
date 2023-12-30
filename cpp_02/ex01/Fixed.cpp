#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    mvalue = 0;
}
//default constructor

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}
//Destructor

Fixed::Fixed(const Fixed &origin){
    std::cout << "Copy constructor called" << std::endl;
    this->mvalue = origin.mvalue;
}
//copy constructor

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return mvalue;
}
//getter

void  Fixed::setRawBits(const int raw){
    mvalue = raw;
}
//setter

Fixed& Fixed::operator=(const Fixed& obj) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->mvalue = obj.getRawBits();
	}
	return (*this);
}
//copy Assignment operator

Fixed::Fixed(int num){
    std::cout << "Int constructor called" << std::endl;
    mvalue = num << mbit;
}
//constructor (int parameter)

Fixed::Fixed(float num){
    std::cout << "Float constructor called" << std::endl;
    this->mvalue = roundf(num *(1 << mbit)) ;
}
//constructor (float parameter)

float	Fixed::toFloat(void) const {
	return ((float)mvalue / (1 << mbit)); 
}

int	Fixed::toInt(void) const {
	return (mvalue >> mbit);
}