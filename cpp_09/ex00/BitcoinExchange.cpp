#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string fname)
{
    loadDataBase(fname);
}

void BitcoinExchange::loadDataBase(std::string fname){
    std::ifstream file(fname);
    if (!file.is_open()){
        throw std::runtime_error("Error: could not open database");
    }
    std::string line;
    while (std::getline(file, line)){
        std::stringstream ss(line);
        std::string data;
        
    }
    return ;

}

BitcoinExchange::~BitcoinExchange()
{
}
