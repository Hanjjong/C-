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
    Fixed(const Fixed& origin);
    Fixed& operator=(const Fixed& obj) ;
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat(void) const;
    int	toInt(void) const;
};

#endif