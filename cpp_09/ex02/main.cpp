#include "PmergeMe.hpp"

//./PmergeMe `jot -r 10 1 20 | tr '\n' ' '` > a.txt
static void checkArgument(int ac) {
    if (ac < 2)
        throw std::invalid_argument("Error: invalid input");
}


int main(int ac, char* av[]) {
    try {
        checkArgument(ac);
        PmergeMe pm;
        pm.initNumber(av);
        pm.makeJacobsthal();

        //vector
        double vec_start_time = clock();
        pm.initVec();
        pm.mergeInserttionReculsive(1);
        double vec_end_time = clock();

        //deque
        double deq_start_time = clock();
        pm.initDeq();
        pm.deqMergeInsertionReculsive(1);
        double deq_end_time = clock();

        pm.printDeqNumbers("Before: ");
        pm.printDeqNumbers("After: ");
        double vec_time = (vec_end_time - vec_start_time) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << pm.getNumberSize() << " elements with vector : " << std::fixed << std::setprecision(6) << vec_time << "s" << std::endl;
        
        double deq_time = (deq_end_time - deq_start_time) / CLOCKS_PER_SEC;
        std::cout << "Time to process a range of " << pm.getNumberSize() << " elements with deque : " << std::fixed << std::setprecision(6) << deq_time << "s" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what();
        return 1;
    }
    return 0;
}