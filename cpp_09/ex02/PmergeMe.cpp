#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const PmergeMe& obj) {
    (void) obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& origin){
       if(this != &origin){
        ;
    }
    return (*this);
}

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::makeJacobsthal()
{
    this->jacobsthal.push_back(0);
    this->jacobsthal.push_back(1);
    int index = 2;
    while (jacobsthal[index - 1] < this->numbersSize) {
        int number = this->jacobsthal[index - 1] + 2 * jacobsthal[index - 2];
        this->jacobsthal.push_back(number);
        index++;
    }
}

void PmergeMe::initNumber(char *av[])
{
    char *ptr;
    int i = 1;

    while (av[i]) {
        double num = std::strtod(av[i], &ptr);
        if (*ptr || num > 2147483647 || num < 1)
            throw std::invalid_argument("Error: invalid num input");
        int insertNum = static_cast<int>(num);
        this->originVec.push_back(insertNum);
        this->originDeq.push_back(insertNum);
        i++;
    }
    this->numbersSize = i - 1;
}

int PmergeMe::getNumberSize()
{
    return this->numbersSize;
}

void PmergeMe::initVec()
{
    this->vec = this-> originVec;
}

void PmergeMe::printNumbers(std::string string)
{
    std::cout << string;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::mergeInserttionReculsive(int size)
{
    std::vector<int> remain;
    
    if (size * 2 > static_cast<int>(vec.size()))
        return ;
    this->findRemain(remain, size * 2);
    this->swapMainChainNum(size);
    this->mergeInserttionReculsive(size * 2);
    this->insertElement(size, remain);  
}

void PmergeMe::findRemain(std::vector<int> &remain, int size)
{
    std::vector<int>::iterator it = vec.begin();
    if (vec.size() % size != 0) {
        int index = (vec.size() / size) * size;
        remain.insert(remain.begin(), it + index, vec.end());
        vec.erase(it + index, vec.end());
    }
}

void PmergeMe::separateElements(std::vector<std::vector<int> >& a, std::vector<std::vector<int> >& b, int size, std::vector<int> remain)
{
    int indexA = 0;
    int indexB = indexA + size;
    while (indexB + size <= static_cast<int>(vec.size())) {
        std::vector<int> mainChainElement;
        std::vector<int> penddingChainElement;
        mainChainElement.insert(mainChainElement.begin(), vec.begin() + indexA, vec.begin() + indexA + size);
        penddingChainElement.insert(penddingChainElement.begin(), vec.begin() + indexB, vec.begin() + indexB + size);
        a.push_back(mainChainElement);
        b.push_back(penddingChainElement);
        indexA += (2 * size);
        indexB += (2 * size);
    }
    if (remain.size() != 0) {
        b.push_back(remain);
    }
}

void PmergeMe::insertElement(int size, std::vector<int> remain)
{
    std::vector<std::vector<int> > a;
    std::vector<std::vector<int> > b;

    int start = 0;
    int end = 0;
    size_t i = 1;
    size_t cnt = 1;
    this->separateElements(a, b, size, remain);
    a.insert(a.begin(), b[0]);

    while (cnt < b.size()) {
        start = this->jacobsthal[i];
        if (start > static_cast<int> ((b.size()) - 1)) {
            start = (b.size()) - 1;
        }
        end = this->jacobsthal[i - 1];
        while (start > end)
        {
            this->binarySearchInsert(a, b[start], 0, start + cnt - 1, size);
            cnt++;
            start--;
        }
    i++;
    }
    std::vector<int> tmp;
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[i].size(); j++) {
            tmp.push_back(a[i][j]);
        }
    }
    vec = tmp;
}

void PmergeMe::binarySearchInsert(std::vector<std::vector<int> >& a, std::vector<int> tmp, int low, int high, int size)
{
    int mid = ((low + high) / 2);

    if (low <= high) {
        if (a[mid][0] > *tmp.begin())
            binarySearchInsert(a, tmp, low, (mid - 1), size);
        else if (a[mid][0] < *tmp.begin())
            binarySearchInsert(a, tmp, (mid + 1), high, size);
        else if (a[mid][0] == *tmp.begin()){
            a.insert(a.begin() + mid, tmp);
        }
        return ;
    }
    a.insert(a.begin() + low, tmp);
    return ;
}

void PmergeMe::swapVecElements(int indexA, int size)
{
    for (int i = 0; i < size; i++) {
        std::swap(vec[indexA + i], vec[indexA + size + i]);
    }
}

void PmergeMe::swapMainChainNum(int size)
{
    int indexA = 0;
    int indexB = indexA + size;
    while (indexB + size <= static_cast<int>(this->vec.size())) {
        if (vec[indexA] < vec[indexB])
            swapVecElements(indexA, size);
        indexA += (2 * size);
        indexB = indexA + size;
    }
}








void PmergeMe::initDeq()
{
    this->deq = this-> originDeq;
}

void PmergeMe::printDeqNumbers(std::string string)
{
    std::cout << string;
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


void PmergeMe::deqFindRemain(std::deque<int> &remain, int size)
{
    std::deque<int>::iterator it = deq.begin();
    if (deq.size() % size != 0) {
        int index = (deq.size() / size) * size;
        remain.insert(remain.begin(), it + index, deq.end());
        deq.erase(it + index, deq.end());
    }
}

void PmergeMe::deqMergeInsertionReculsive(int size)
{
    std::deque<int> remain;
    
    if (size * 2 > static_cast<int>(deq.size()))
        return ;
    this->deqFindRemain(remain, size * 2);
    this->deqSwapMainChainNum(size);
    this->deqMergeInsertionReculsive(size * 2);
    this->deqInsertElement(size, remain);  

}


void PmergeMe::deqSeparateElements(std::deque<std::deque<int> >& a, std::deque<std::deque<int> >& b, int size, std::deque<int> remain)
{
    int indexA = 0;
    int indexB = indexA + size;
    while (indexB + size <= static_cast<int>(deq.size())) {
        std::deque<int> mainChainElement;
        std::deque<int> penddingChainElement;
        mainChainElement.insert(mainChainElement.begin(), deq.begin() + indexA, deq.begin() + indexA + size);
        penddingChainElement.insert(penddingChainElement.begin(), deq.begin() + indexB, deq.begin() + indexB + size);
        a.push_back(mainChainElement);
        b.push_back(penddingChainElement);
        indexA += (2 * size);
        indexB += (2 * size);
    }
    if (remain.size() != 0) {
        b.push_back(remain);
    }
}

void PmergeMe::deqInsertElement(int size, std::deque<int> remain)
{
    std::deque<std::deque<int> > a;
    std::deque<std::deque<int> > b;

    int start = 0;
    int end = 0;
    size_t i = 1;
    size_t cnt = 1;
    this->deqSeparateElements(a, b, size, remain);
    a.insert(a.begin(), b[0]);

    while (cnt < b.size()) {
        start = this->jacobsthal[i];
        if (start > static_cast<int> ((b.size()) - 1)) {
            start = (b.size()) - 1;
        }
        end = this->jacobsthal[i - 1];
        while (start > end)
        {
            this->deqBinarySearchInsert(a, b[start], 0, start + cnt - 1, size);
            cnt++;
            start--;
        }
    i++;
    }
    std::deque<int> tmp;
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[i].size(); j++) {
            tmp.push_back(a[i][j]);
        }
    }
    deq = tmp;
}

void PmergeMe::deqBinarySearchInsert(std::deque<std::deque<int> >& a, std::deque<int> tmp, int low, int high, int size)
{
    int mid = ((low + high) / 2);

    if (low <= high) {
        if (a[mid][0] > *tmp.begin())
            deqBinarySearchInsert(a, tmp, low, (mid - 1), size);
        else if (a[mid][0] < *tmp.begin())
            deqBinarySearchInsert(a, tmp, (mid + 1), high, size);
        else if (a[mid][0] == *tmp.begin()){
            a.insert(a.begin() + mid, tmp);
        }
        return ;
    }
    a.insert(a.begin() + low, tmp);
    return ;
}

void PmergeMe::SwapDeqElements(int indexA, int size)
{
    for (int i = 0; i < size; i++) {
        std::swap(deq[indexA + i], deq[indexA + size + i]);
    }
}

void PmergeMe::deqSwapMainChainNum(int size)
{
    int indexA = 0;
    int indexB = indexA + size;
    while (indexB + size <= static_cast<int>(this->deq.size())) {
        if (deq[indexA] < deq[indexB])
            SwapDeqElements(indexA, size);
        indexA += (2 * size);
        indexB = indexA + size;
    }
}

void PmergeMe::checkSort()
{
    for (size_t i = 1; i < deq.size(); i++) {
        if (deq[i] < deq[i - 1])
        {
            std::cout << std::endl;
            std::cout << "error";
            return;
        }
    }
    std::cout << std::endl;
    std::cout << deq.size();
    std::cout << std::endl;
    std::cout << "SORTING!!!!!!";
}
