#include "Serializer.hpp"

Serializer::~Serializer(){}

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &origin){}

Serializer& Serializer::operator=(const Serializer &obj){}

static uintptr_t serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

static Data* deserialize(uintptr_t raw){
    return reinterpret_cast<Data *>(raw);
}