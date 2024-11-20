#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::initNumber(char *av[])
{
    char *ptr;
    int i = 0;

    while (!av[i]) {
        double num = std::strtod(av[i], &ptr);
        if (*ptr || num > 2147483647 || num < 1)
            throw std::invalid_argument("Error: invalid num input");
        int insertNum = static_cast<int>(num);
        this->vec.push_back(insertNum);
        this->deq.push_back(insertNum);
    }

}
