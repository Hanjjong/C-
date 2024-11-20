#include "PmergeMe.hpp"

static void checkArgument(int ac) {
    if (ac != 2)
        throw std::invalid_argument("Error: invalid input");
}


int main(int ac, char* av[]) {
    try {
        checkArgument(ac);

        PmergeMe pm;
        pm.initNumber(av);

    } catch (const std::exception& e) {
        return 1;
    }
    return 0;
}