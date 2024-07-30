#include "Span.hpp"

Span::Span() : size(0) {}

Span::~Span() {}

Span::Span(const Span &origin) : vec(origin.vec), size(origin.size) {}

Span &Span::operator=(const Span &obj)
{
    if(this != &obj){
        this->vec = obj.vec;
        this->size = obj.size;
    }
    return *this;
}

Span::Span(unsigned int N)
{
    this->vec.reserve(N);
    this->size = N;
}

void Span::addNumber(int n)
{
    if (this->vec.size() == size)
        throw CannotAddNumberException();
    vec.push_back(n);
}

void Span::addNumbers(int begin, int end)
{
    if (this->vec.size() == this->size)
        throw CannotAddNumberException();
    for (int i = begin; i <= end; i++){
        if (this->vec.size() == this->size)
            throw CannotAddNumberException();
        vec.push_back(i);
    }
}

int Span::shortestSpan()
{
    int minSpan = 2147483647;
    if (this->vec.size() <= 1){
        throw CannotFoundSpanException();
    }
    std::sort(vec.begin(), vec.end());
    for (size_t i = 0; i < vec.size() - 1; ++i){
        int diff = vec[i + 1] - vec[i];
        if (diff < minSpan){
            minSpan = diff;
        }
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (this->vec.size() <= 1){
        throw CannotFoundSpanException();
    }
    return (*std::max_element(vec.begin(), vec.end()) 
        - *std::min_element(vec.begin(), vec.end()));
}

const char *Span::CannotAddNumberException::what() const throw()
{
    return "CannotAddNumberException!!";
}

const char *Span::CannotFoundSpanException::what() const throw()
{
    return "CannotFoundSpanException!!";
}
