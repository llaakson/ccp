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
            std::vector<int> _temp_pend;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe &copy);
        PmergeMe& operator=(PmergeMe &rhs);

        void start(std::vector<int> &container, int _level);
        long jacobsthal_number(long n);

        int getComparison();
        void create_temp_pend(std::vector<int> &temp_pend, int level,int jacob,int shit, int flag);
        std::vector<int>::iterator find_insert_position(std::vector<int> &main, int position);

};
