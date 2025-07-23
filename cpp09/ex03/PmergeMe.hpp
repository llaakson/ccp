#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iterator>
#include <iostream>
#include <list>
#include <map>

#include <algorithm>
#include <cmath>

class PmergeMe {
    private:
        int _uneven_side_number;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe &rhs);

        void merge_insertion_sort(std::vector<int> aa, int level);

};

#endif