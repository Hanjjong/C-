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
        Span(const Span& origin);
        Span& operator=(const Span& obj);
        void addNumber(unsigned int n);
        template <typename InputIterator>
        void addNumbers(InputIterator begin, InputIterator end)
        {
            if (std::distance(begin, end) > static_cast<int>(this->size - this->vec.size()))
                throw CannotAddNumberException();
            this->vec.insert(this->vec.end(), begin, end);
        }
        int shortestSpan();
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