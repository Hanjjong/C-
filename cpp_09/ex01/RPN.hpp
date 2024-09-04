#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>

class RPN{

public:
    int evaluate(const std::string &expression);

private:
    RPN();
    RPN(const RPN& origin);
    RPN& operator=(const RPN &obj);
    ~RPN();
    
    bool isOperator(const std::string &token);
    int applyOperation(const std::string &operation, int operand1, int operand2);

};
#endif