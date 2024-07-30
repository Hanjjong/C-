#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *array, int size, F f){
    for (int i = 0; i < size; i++){
        f(array[i]);
    }
}
//(void *)(f)(int&)

template <typename T>
void printElement(T& element){
    std::cout << element << " ";
}

#endif