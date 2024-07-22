#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>


template <typename T>
void swap(T& a, T& b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename MIN>
MIN& min(MIN& a, MIN& b){
    if (a >= b)
        return b;
    return a;
}

template <typename MAX>
MAX& max(MAX& a, MAX& b){
    if (a <= b)
        return b;
    return a;
}

#endif