#include "PmergeMe.hpp"

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
    while (jacobsthal[index - 1] < this->size) {
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
        this->vec.push_back(insertNum);
        i++;
    }
    this->size = i - 1;
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

    
    if (size * 2 > static_cast<int>(vec.size()))
        return ;
    std::cout << size ;
    this->printNumbers(": ");
    this->swapMainChainNum(size);
    this->mergeInserttionReculsive(size * 2);
    this->insertElement(size);
    this->printNumbers("finish: ");
    std::cout << "remainingNumbers : ";
    for (size_t j = 0; j < remainNumbers.size(); j++){
        std::cout << remainNumbers[j] << " "; 
    }
    std::cout << std::endl;    
}

void PmergeMe::separateElements(std::vector<std::vector<int> >& a, std::vector<std::vector<int> >& b, int size)
{
    this->printNumbers("vec : ");
    std::cout << "size: " << size << std::endl;
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

    if (indexA < static_cast<int>(vec.size())) { 
        // 남은 부분을 B에 추가
        std::vector<int> remainElement;
        remainElement.insert(remainElement.begin(), vec.begin() + indexA, vec.end());
        if (this->remainNumbers.size() > 0) {
            this->remainNumbers.clear();
            this->remainNumbers = remainElement;
        }
    }

}

void PmergeMe::insertElement(int size)
{
    std::vector<std::vector<int> > a;
    std::vector<std::vector<int> > b;

    int start = 0;
    int end = 0;
    size_t i = 1;
    size_t cnt = 1;
    this->separateElements(a, b, size);
    a.insert(a.begin(), b[0]);

    while (cnt < b.size()) {
        start = this->jacobsthal[i];
        if (start > static_cast<int> ((b.size()) - 1)) {
            start = (b.size()) - 1;
        }
        end = this->jacobsthal[i - 1];
        while (start > end)
        {
            this->binarySearchInsert(a, b[start - 1], 0, start + cnt - 1, size);

            cnt++;
            start--;
        }
    i++;
    }
    a.push_back(remainNumbers);

    // 완성된 메인체인을 원본에 복사
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

void PmergeMe::checkSort()
{
    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1])
        {
            std::cout << "error";
            return;
        }
    }
    std::cout << std::endl;
    std::cout << "SORTING!!!!!!";
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
