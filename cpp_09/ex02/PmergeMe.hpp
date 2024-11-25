#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
    std::vector<int> originVec;
    std::deque<int> originDeq;
    std::vector<int> vec;
    std::deque<int> deq;
    std::vector<int> jacobsthal;
    int numbersSize;

public:
    PmergeMe(/* args */);
    ~PmergeMe();
    void makeJacobsthal();
    void initNumber(char* av[]);
    int getNumberSize();

    void initVec();
    void printNumbers(std::string string);
    void mergeInserttionReculsive(int size);
    void findRemain(std::vector<int> &remain, int size);
    void insertElement(int size, std::vector<int> remain);
    void binarySearchInsert(std::vector<std::vector<int> >& a, std::vector<int> tmp, int low, int high, int size);    
    void separateElements(std::vector<std::vector<int> >& a, std::vector<std::vector<int> >& b, int size, std::vector<int> remain);
    void swapMainChainNum(int size);
    void swapVecElements(int indexA, int size);


    void initDeq();
    void printDeqNumbers(std::string string);
    void deqMergeInsertionReculsive(int size);
    void deqFindRemain(std::deque<int> &remain, int size);
    void deqInsertElement(int size, std::deque<int> remain);
    void deqBinarySearchInsert(std::deque<std::deque<int> >& a, std::deque<int> tmp, int low, int high, int size);    
    void deqSeparateElements(std::deque<std::deque<int> >& a, std::deque<std::deque<int> >& b, int size, std::deque<int> remain);
    void deqSwapMainChainNum(int size);
    void SwapDeqElements(int indexA, int size);








    void checkSort();
};

#endif