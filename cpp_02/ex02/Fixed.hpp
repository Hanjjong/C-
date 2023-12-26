#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

private:
    int mvalue;
    static const int mbit = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(int value);
    Fixed(float value);
    Fixed(const Fixed& origin); //복사 생성자
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat(void) const;
    int	toInt(void) const;
    
    Fixed& operator=(const Fixed& obj) ;
    bool	operator>(const Fixed &ref) const;
    bool	operator<(const Fixed &ref) const;
    bool	operator>=(const Fixed &ref) const;
    bool	operator<=(const Fixed &ref) const;
    bool	operator==(const Fixed &ref) const;
    bool	operator!=(const Fixed &ref) const;
    Fixed	operator+(const Fixed &ref) const;
    Fixed	operator-(const Fixed &ref) const;
    Fixed	operator*(const Fixed &ref) const;
    Fixed	operator/(const Fixed &ref) const;
    Fixed	&operator++(void);
    const Fixed	operator++(int);
    Fixed	&operator--(void);
    const Fixed	operator--(int);

    static Fixed	&min(Fixed &ref1, Fixed &ref2);
    static const Fixed	&min(Fixed const &ref1, Fixed const &ref2);
    static Fixed	&max(Fixed &ref1, Fixed &ref2);
    static const Fixed	&max(Fixed const &ref1, Fixed const &ref2);
};

#endif