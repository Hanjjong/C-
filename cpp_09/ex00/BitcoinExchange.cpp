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
        std::string date;
        float rate;
        if (std::getline(ss, date, ',') && ss >> rate){
            bitcoinData[date] = rate;
        }
    }
    // bitcoinData 맵 출력
    // for (std::map<std::string, float>::iterator it = bitcoinData.begin(); it != bitcoinData.end(); ++it){
    //     std::cout << it->first << " " << it->second << std::endl; 
    // }
    file.close();
    return ;
}

void BitcoinExchange::is_valid_date(std::string date)
{
    if (date.length() != 11){
        throw std::runtime_error("Error: Invalid input date");
    }
    int i = 0;
    while (date[i]){
        // - 위치 , 윤년 확인
        i++;
    }
}

double BitcoinExchange::getExchangeRate(std::string date)
{
    std::string closestDate = findClosestDate(date);

    return 0.0;
}

std::string BitcoinExchange::findClosestDate(std::string date)
{
    std::map<std::string, float>::const_iterator it = bitcoinData.lower_bound(date);

    // 주어진 날짜와 정확히 일치하는 날짜가 있는 경우
    if (it != bitcoinData.end() && it->first == date) {
        return it->first;
    }

    // 주어진 날짜보다 이후의 날짜를 가리키는 경우
    if (it != bitcoinData.begin()) {
        --it; // 이전 날짜로 이동
        return it->first;
    }

    // 모든 날짜가 주어진 날짜보다 이후인 경우
    return "";
}

double BitcoinExchange::is_valid_value(std::string input)
{
    char* endptr;
    double rate = std::strtod(input.c_str(), &endptr);
    
    // 변환이 실패한 경우, endptr이 input의 시작 주소와 같음.
    if (input.c_str() == endptr || rate < 0) {
        throw std::runtime_error("Error: Invalid input rate");
    }
    return rate;
}

void BitcoinExchange::processInput(std::string fname){
    std::ifstream file(fname);
    if (!file.is_open()){
        throw std::runtime_error("Error: could not open input data");
    }

    std::string line;
    std::getline(file, line);
    if (line != "data | value")
        throw std::runtime_error("Invalid data fomat");
    while (std::getline(file, line)){
        std::stringstream ss(line);
        std::string date;
        std::string rate;
        if (std::getline(ss, date, '|') && ss >> rate){
            int valid_value;
            try{
                is_valid_date(date);
            }
            catch (const std::exception& e){
                std::cerr << e.what() << std::endl;
            }
            try{
                valid_value = is_valid_value(rate);
            }
            catch (const std::exception& e){
                std::cerr << e.what() << std::endl;
            }

            int rate = getExchangeRate(date);
            inputData[date] = valid_value;
            std::cout << date << "=> " << inputData[date] << std::endl;
        }
    }
}


BitcoinExchange::~BitcoinExchange()
{
}
