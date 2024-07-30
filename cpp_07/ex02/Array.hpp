#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
    private:
        T* elements;
        unsigned int arraySize;
    public:
        Array() : elements(0), arraySize(0) {}

        Array(unsigned int n) : arraySize (n) {
            elements = new T[n];
        }

        ~Array(){
            delete[] elements;
        }

        Array(const Array& obj) : arraySize(obj.arraySize) {
            elements = new T[arraySize];
            for (unsigned int i = 0; i < arraySize; ++i) {
                elements[i] = obj.elements[i];
            }
        }

        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] elements;
                arraySize = other.arraySize;
                elements = new T[arraySize];
                for (unsigned int i = 0; i < arraySize; ++i) {
                    elements[i] = other.elements[i];
                }
            }
            return *this;
        }

        T& operator[](unsigned int index) {
            if (index >= arraySize) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= arraySize) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }

        unsigned int size() const {
            return arraySize;
        }
};

#endif
