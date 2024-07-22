#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(){
    std::vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 11);
        std::cout << *it << std::endl;
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }

    std::list<int> lst;
    for (int i = 0; i < 10; i++){
        lst.push_back(i);
    }
    try {
        std::list<int>::iterator it = easyfind(lst, 4);
        std::cout << *it << std::endl;
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
}