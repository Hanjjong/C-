#include "Serializer.hpp"

Serializer::~Serializer(){}

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &origin){
    (void)origin;
}

Serializer& Serializer::operator=(const Serializer &obj){
    if(this != &obj){
        ;
    }
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr){

    std::cout << reinterpret_cast<uintptr_t>(ptr) << std::endl;
    std::cout << static_cast<void *>(&ptr) << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}