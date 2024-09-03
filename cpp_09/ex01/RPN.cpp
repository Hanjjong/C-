#include "RPN.hpp"
#include <stack>
#include <string>
#include <sstream>

int RPN::evaluate(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (std::isdigit(token[0])) {
            stack.push(std::stoi(token));
        } else if (isOperator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error("Error");
            }
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();
            int result = applyOperation(token, operand1, operand2);
            stack.push(result);
        } else {
            throw std::runtime_error("Error");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("Error");
    }

    return stack.top();
}

bool RPN::isOperator(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOperation(const std::string &operation, int operand1, int operand2) {
    if (operation == "+") return operand1 + operand2;
    if (operation == "-") return operand1 - operand2;
    if (operation == "*") return operand1 * operand2;
    if (operation == "/") {
        if (operand2 == 0) {
            throw std::runtime_error("Error: division by zero");
        }
        return operand1 / operand2;
    }
    throw std::runtime_error("Error");
}