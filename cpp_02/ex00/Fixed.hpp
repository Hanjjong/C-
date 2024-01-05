#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{

private:
    int mvalue;
    static const int mbit = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& origin);
    Fixed& operator=(const Fixed& obj) ;
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif