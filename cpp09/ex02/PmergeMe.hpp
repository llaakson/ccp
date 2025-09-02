#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>

class PmergeMe {
    private:
            int comparison;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe &copy);
        PmergeMe& operator=(PmergeMe &rhs);

        void start(std::vector<int> &container, int _level);
        long jacobsthal_number(long n);

        int getComparison();

};
