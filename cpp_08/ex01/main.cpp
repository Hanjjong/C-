#include "Span.hpp"

int main(){
    try {
        Span sp(5);
        sp.addNumbers(1, 10);
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try {
        Span sp(10);
        sp.addNumbers(3, 8);
        sp.addNumber(20);
        sp.addNumber(1);
        sp.addNumber(12);
        sp.addNumber(15);
        std::cout << "longest Span : " << sp.longestSpan() << std::endl;
        std::cout << "shortest Span : " << sp.shortestSpan() << std::endl; 

    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}