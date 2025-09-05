#include "PmergeMe2.hpp"

PmergeMe::PmergeMe() {
    comparison = 0;
}

int PmergeMe::getComparison(){
    return (comparison);
}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe &copy){
    (void)copy;
}

PmergeMe& PmergeMe::operator=(PmergeMe &rhs){
    (void)rhs;
    return *this;
}

long PmergeMe::jacobsthal_number(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3);}
