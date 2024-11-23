#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::makeJacobsthal()
{
    this->jacobsthal.push_back(1);
    this->jacobsthal.push_back(3);
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
}

void PmergeMe::separateElements(std::vector<int>& a, std::vector<int>& b, int size)
{
    this->printNumbers("vec : ");
    int indexA = 0;
    int indexB = indexA + size;
    while (indexB + size <= static_cast<int>(vec.size())) {
        a.insert(a.end(), vec.begin() + indexA, vec.begin() + indexA + size);
        b.insert(b.end(), vec.begin() + indexB , vec.begin() + indexB + size);
        indexA += (2 * size);
        indexB += (2 * size);
    }

    if (indexA < static_cast<int>(vec.size())) { 
        // 남은 부분을 B에 추가
        b.insert(b.end(), vec.begin() + indexA, vec.end());
    }
    std::cout << "A : ";
    for (size_t i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";

    std::cout << "B : ";
    for (size_t i = 0; i < b.size(); i++) {
        std::cout << b[i] << " ";
    }
    std::cout << "\n";
}

void PmergeMe::insertElement(int size)
{
    std::vector<int> a;
    std::vector<int> b;

    int start = 0;
    int end = 0;
    int i = 1;
    int cnt = 1;
    this->separateElements(a, b, size);

    //-------------
    std::cout << size << "\n";
    std::cout << "a : ";
    for (size_t j = 0; j < a.size(); j++){
        std::cout << a[j] << " "; 
    }
    std::cout << "\n";
    std::cout << " erase b : ";
    for (size_t j = 0; j < b.size(); j++){
        std::cout << b[j] << " "; 
    }
    std::cout << "\n";
    //-------------------

    a.insert(a.begin(), b.begin(), b.begin() + size);
    b.erase(b.begin(), b.begin() + size);
    int pendSize = b.size() / size;


    std::cout << " erase b : ";
    for (size_t j = 0; j < b.size(); j++){
        std::cout << b[j] << " "; 
    }
    std::cout << "\n";  
    
    // 돌아야할 체인의 수 만큼 반복
    std::cout << "cnt : " << cnt << " pendSize : " << pendSize << "\n";
    while (cnt < pendSize) {
        start = this->jacobsthal[i];

        //
        if (start > static_cast<int> (b.size() - 1))
            start = b.size() - 1;
        end = this->jacobsthal[i - 1];
        std::cout << "start end "<< start << " " << end << "\n";
        while (start > end)
        {
            std::vector<int> tmp;
            std::cout << "너가 문제야?\n";
            // tmp.insert(tmp.begin(), b.begin() + (index * size), b.begin() + (index * size) + size);
            tmp.insert(tmp.begin(), b.begin() + (start * size), b.begin() + (start * size) + size);
            std::cout << "tmp: ";
            for (size_t i = 0; i < tmp.size(); i++) 
                std::cout << tmp[i] << " ";
            std::cout << "\n";
            b.erase(b.begin() + (start * size), b.begin() + (start * size) + size);
            this->binarySearchInsert(a, tmp, 0, a.size() - size, size);
            cnt++;
            start--;
        }
    i++;
    }
    this->vec = a;
}

void PmergeMe::binarySearchInsert(std::vector<int>& a, std::vector<int> tmp, int low, int high, int size)
{
    std::vector<int>::iterator it = a.begin();
    int mid = ((low + high) / 2) * size;

    if (low <= high) {
        if (a[mid] > *tmp.begin())
            binarySearchInsert(a, tmp, low, (mid - size), size);
        else if (a[mid] < *tmp.begin())
            binarySearchInsert(a, tmp, (mid + size), high, size);
        else if (a[mid] == *tmp.begin())
            a.insert(it + mid, tmp.begin(), tmp.begin() + size);
            return ;
    }
    a.insert(it + low, tmp.begin(), tmp.begin() + size);
    for (size_t i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
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
