#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <algorithm>
#include <iostream>

class Span{
    private:
        std::vector<int>    vec;
        unsigned int        size;
        Span();
    public:
        Span(unsigned int N);
        ~Span();
        void addNumber(int n);
        void addNumbers(int begin, int end);
        //숫자를 추가하는데 이미 있는 숫자라면 예외
        int shortestSpan();
        //if can't find shortest span throw exception
        int longestSpan();
    class CannotAddNumberException : public std::exception{
        public:
            const char* what() const throw();
    };
    class CannotFoundSpanException : public std::exception{
        public:
            const char* what() const throw();
    };
};

#endif