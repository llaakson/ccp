#include "PmergeMe.hpp"

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

void PmergeMe::short_a_vector(){


}

void PmergeMe::start_merging(int argc, char **argv){
    
    if (argc % 2 == 0)
        _uneven_side_number = atoi(argv[argc-1]);

    for (int i = 1; argc-1 > i; i += 2){
        if (atoi(argv[i]) < atoi(argv[i+1])){
            _a_vector.push_back(std::stoi(argv[i]));
            _b_deque.push_back(std::stoi(argv[i+1]));}
        else{
            _a_vector.push_back(std::stoi(argv[i+1]));
            _b_deque.push_back(std::stoi(argv[i]));}
    }
    
    // if (!(is_sorted(_a_vector.begin(), _a_vector.end())))
    //     start_merging(_a_vector.size(), )
    std::cout << "A list" << std::endl;
    for (auto it = _a_vector.begin(); it != _a_vector.end(); ++it){
        std::cout << *it << std::endl;}

    std::cout << "B list" << std::endl;
    for (auto it = _b_deque.begin(); it != _b_deque.end(); ++it){
        std::cout << *it << std::endl;}

     if (argc % 2 == 0){
         std::cout << "Side piece : " << _uneven_side_number << std::endl;}
    else
        std::cout << "No side piece" << std::endl;
    
 }