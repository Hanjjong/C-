#include "Span.hpp"
#include <list>

int main(){
    try {
        Span sp(5);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(5);
        sp.addNumber(6);
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    try {
        std::vector<int> v;
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);
        v.push_back(7);
        v.push_back(8);


        Span sp(10);
        sp.addNumbers(v.begin(), v.end());
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
    try {
        std::list<int> lst;
        lst.push_back(3);
        lst.push_back(4);
        lst.push_back(5);
        lst.push_back(6);
        lst.push_back(7);
        lst.push_back(8);

        Span sp(10);
        sp.addNumbers(lst.begin(), lst.end());
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