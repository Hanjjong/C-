#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <fstream>
#include <sstream>

#include <map>
class BitcoinExchange
{
private:
    /* data */
    void loadDataBase(std::string fname);
    std::map<std::string, float> bitcoinData;
public:
    BitcoinExchange(std::string fname);
    ~BitcoinExchange();
};



#endif