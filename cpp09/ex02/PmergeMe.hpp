#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iterator>
#include <iostream>
#include <deque>

#include <bits/stdc++.h>

class PmergeMe {
    private:
        std::vector<int> _a_vector;
        std::deque<int> _b_deque;
        int _uneven_side_number;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe();
        PmergeMe& operator=(const PmergeMe &rhs);

        void start_merging(int argc, char **argv);
        void short_a_vector();
};

#endif