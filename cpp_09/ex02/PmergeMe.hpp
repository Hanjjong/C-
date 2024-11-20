#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
// #include <exception>

class PmergeMe
{
private:
    std::vector<int> vec;
    std::deque<int> deq;
public:
    PmergeMe(/* args */);
    ~PmergeMe();
    void initNumber(char* av[]);
};

#endif