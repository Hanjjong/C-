#include "Serializer.hpp"

int main(){
    uintptr_t num;

    Data data;
    data.name = "data";
    data.value = 1000;
    num = Serializer::serialize(&data);
    std::cout << Serializer::deserialize(num)->name << ", " << Serializer::deserialize(num)->value;
}