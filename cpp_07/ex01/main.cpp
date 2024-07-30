#include "iter.hpp"

int main(){
    int array[10] = {1,2,3,4,5,6,7,8,9,0};
    iter(array, 10, printElement<int>);
    std::cout << std::endl;
    return 0;
}