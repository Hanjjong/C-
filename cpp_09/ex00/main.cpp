#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[]){
    if (argc != 2){
        std::cerr << "Invalid Input" << std::endl;
        return 1;
    }
    try{
        BitcoinExchange exchange("data.csv");
        exchange.processInput(argv[1]);

    }catch(const std::exception& e){
        std::cerr << e.what() ;
    }

    return 0;
}