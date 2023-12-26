#include "Fixed.hpp"
std::ostream& operator<< (std::ostream &out, const Fixed &fixed){
    out << fixed.toFloat();
    return out;
}

int main()
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    if (a != b){
        std::cout << "다르지롱~~~~" << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "a + b = "<<  a + b << std::endl;
    }
    
    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    return 0;
}