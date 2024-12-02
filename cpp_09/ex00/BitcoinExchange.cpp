#include "BitcoinExchange.hpp"

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &origin)
{
    if(this != &origin){
        ;
    }
    return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
    (void) obj;
}

BitcoinExchange::BitcoinExchange(std::string fname) { loadDataBase(fname); }

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string& str) {
    std::string::size_type start = 0;
    while (start < str.size() && std::isspace(str[start])) {
        ++start;
    }
    std::string::size_type end = str.size();
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }
    return str.substr(start, end - start);
}

static bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
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
            bitcoinData[trim(date)] = rate;
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
    int year = 0;
    int month = 0;
    int day = 0;

    if (date.length() != 10){
        throw std::runtime_error("Error: bad input => " + date);
    }
    // check year;
    std::stringstream ss;
    int i = 0;
    while (date[i] != '-'){
        if (!std::isdigit(date[i]))
            throw std::runtime_error("Error: bad input => " + date);
        ss << date[i];
        i++;
    }
    ss >> year;
    ss.clear();
    if (i != 4 || year < 2009 || date[i] != '-')
        throw std::runtime_error("Error: bad input => " + date);
    i++;

    // check month;
    while (date[i] != '-'){
        if (!std::isdigit(date[i]))
            throw std::runtime_error("Error: bad input => " + date);
        ss << date[i];
        i++;    
    }
    ss >> month;
    ss.clear();
    if (i != 7 || month < 1 || month > 12 || date[i] != '-')
        throw std::runtime_error("Error: bad input => " + date);
    i++;    

    //check day;
    while (date[i]){
        if (!std::isdigit(date[i]))
            throw std::runtime_error("Error: bad input => " + date);
        ss << date[i];
        i++;    
    }
    ss >> day;
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    // 윤년일 경우 2월의 일자 조정
    if (isLeapYear(year))
        daysInMonth[1] = 29;
    if (day < 1 || day > daysInMonth[month - 1]) {
        throw std::runtime_error("Error: bad input => " + date);
    }
}

float BitcoinExchange::getExchangeRate(std::string date)
{
    std::string closestDate = findClosestDate(date);
    if (closestDate == "")
        throw std::runtime_error("해당하는 날짜의 환율이 없습니다...");

    return bitcoinData[closestDate];
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

float BitcoinExchange::is_valid_value(std::string input)
{
    char* endptr;
    float rate = std::strtof(input.c_str(), &endptr);
    
    // 변환이 실패한 경우, endptr이 input의 시작 주소와 같음.
    if (input.c_str() == endptr)
        throw std::runtime_error("Error: Rate value doesn't exist");
    if (rate < 0) 
        throw std::runtime_error("Error: not a positive number.");
    if (rate > 1000)
        throw std::runtime_error("Error: too large a number.");
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
        if (line.empty())
            continue;
        std::stringstream ss(line);
        std::string date;
        std::string rate;
        if (std::getline(ss, date, '|')) {
            date = trim(date); 
            if (line.empty())
                continue;
            std::getline(ss, rate);
            rate = trim(rate); 
            try {
                // 날짜 및 값 유효성 검사
                is_valid_date(date);
                float valid_value = is_valid_value(rate);

                // 환율 가져오기 및 계산
                float exchangeRate = getExchangeRate(date);
                inputData[date] = valid_value;
                
                std::cout << date << " => " << inputData[date] << " = " << exchangeRate * inputData[date] << std::endl;
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}


