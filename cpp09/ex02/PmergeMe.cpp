#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

PmergeMe::PmergeMe() : _uneven_side_number(0) {}

PmergeMe::PmergeMe(const PmergeMe &copy){
    *this = copy;
}

PmergeMe::~PmergeMe(){}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs){
    if (this != &rhs)
        return *this;
    return *this;
}

std::vector<int> PmergeMe::start_merging(std::vector<int> A_vector){
   
    if (A_vector.size() <= 1)
        return (A_vector);
    if (A_vector.size() % 2 == 0){
        _uneven_side_number = A_vector.back();
        A_vector.pop_back();}

    std::deque<int> _a_deque;
    std::deque<int> _b_deque;
    for (size_t i = 0; A_vector.size()-1 > i; i += 2)
    {
        if (A_vector[i] < A_vector[i+1])
        {
            _a_deque.push_back(A_vector[i]);
            _b_deque.push_back(A_vector[i+1]);
        }
        else
        {
            _a_deque.push_back(A_vector[i+1]);
            _b_deque.push_back(A_vector[i]);
        }
        std::cout << "A list" << std::endl;
    }
    
    std::cout << "A list" << std::endl;
    for (auto it = _a_deque.begin(); it != _a_deque.end(); ++it){
        std::cout << *it << std::endl;}

    std::map<int,int> pair_map;
    for (size_t i = 0; i < _a_deque.size(); ++i){
        pair_map.insert({_a_deque[i],_b_deque[i]});
    }
    std::cout << "map" << std::endl;
    for (auto it = pair_map.begin(); it != pair_map.end(); it++){
	  	std::cout << "'" << it->first << " ' '" << it->second << "'" << std::endl;
      }

    
    // std::cout << "A list final" << std::endl;
    // for (auto it = sorted_A.begin(); it != sorted_A.end(); ++it){
    //     std::cout << *it << std::endl;}
    
    // std::cout << "A list" << std::endl;
    // for (auto it = _a_deque.begin(); it != _a_deque.end(); ++it){
    //     std::cout << *it << std::endl;}

    // std::cout << "B list" << std::endl;
    // for (auto it = _b_deque.begin(); it != _b_deque.end(); ++it){
    //     std::cout << *it << std::endl;}

     if (2 % 2 == 0){
         std::cout << "Side piece : " << _uneven_side_number << std::endl;}
    else
        std::cout << "No side piece" << std::endl;
    return A_vector;
 }