#include "Fixed.hpp"

Fixed::Fixed(){
    mvalue = 0;
}
Fixed::~Fixed(){
}

Fixed::Fixed(const Fixed &origin){
	std::cout << "asd" << std::endl;
    this->mvalue = origin.mvalue;
}

int Fixed::getRawBits( void ) const{
    return mvalue;
}

void  Fixed::setRawBits(const int raw){
    mvalue = raw;
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

Fixed& Fixed::operator=(const Fixed& obj) 
{
	if (this != &obj)
	{
		this->mvalue = obj.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(Fixed const &ref) const
{
	return (this->getRawBits() > ref.getRawBits());
}

bool	Fixed::operator<(Fixed const &ref) const
{
	return (this->getRawBits() < ref.getRawBits());
}

bool	Fixed::operator>=(Fixed const &ref) const
{
	return (this->getRawBits() >= ref.getRawBits());
}

bool	Fixed::operator<=(Fixed const &ref) const
{
	return (this->getRawBits() <= ref.getRawBits());
}

bool	Fixed::operator==(Fixed const &ref) const
{
	return (this->getRawBits() == ref.getRawBits());
}

bool	Fixed::operator!=(Fixed const &ref) const
{
	return (this->getRawBits() != ref.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &ref) const
{
	Fixed fixed(this->toFloat() + ref.toFloat());
	return (fixed);
}

Fixed Fixed::operator-(Fixed const &ref) const
{
	Fixed fixed(this->toFloat() - ref.toFloat());
	return (fixed);
}

Fixed Fixed::operator*(Fixed const &ref) const
{
	Fixed fixed(this->toFloat() * ref.toFloat());
	return (fixed);
}

Fixed Fixed::operator/(Fixed const &ref) const
{
	Fixed fixed(this->toFloat() / ref.toFloat());
	return (fixed);
}

Fixed& Fixed::operator++(void)
{
	this->mvalue++;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	ret(*this);

	this->mvalue++;
	return (ret);
}

Fixed& Fixed::operator--(void)
{
	this->mvalue--;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed	ret(*this);

	this->mvalue--;
	return (ret);
}

Fixed& Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed& Fixed::min(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 <= ref2)
		return ref1;
	else
		return ref2;
}

Fixed& Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}

const Fixed& Fixed::max(Fixed const &ref1, Fixed const &ref2)
{
	if (ref1 >= ref2)
		return ref1;
	else
		return ref2;
}