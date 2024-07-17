#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>


struct Data{
    std::string name;
    int value;
};

class Serializer{
    private:
        Serializer();
        Serializer(const Serializer &origin);
        Serializer& operator=(const Serializer &obj);
        ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif