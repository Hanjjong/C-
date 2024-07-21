#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T elements;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& obj);
        Array& operator=(const Array& origin);
        
};

#endif