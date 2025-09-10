#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe(){}

long PmergeMe::jacobsthal_number(long n)
{ 
    return round((pow(2, n + 1) + pow(-1, n)) / 3);
}
