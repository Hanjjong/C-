#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[]){
    if (argc != 3){
        std::cerr << "Invalid Input" << std::endl;
    }
    try{
        BitcoinExchange exchange("data.csv");

    }catch(const std::exception& e){

    }

    return 0;
}