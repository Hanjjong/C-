#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{

private:
    int m_pointnumber;
    static const int m_rawbit;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& origin);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    //◦ A copy assignment operator overload.
};

#endif