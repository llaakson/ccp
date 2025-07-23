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


void PmergeMe::merge_insertion_sort(std::vector<int> aa, int level){
 
    int pair_units_nbr = aa.size() / level;
    if (pair_units_nbr < 2)
        return;
    std::cout << "pair_units_nbr: " << pair_units_nbr << " level: " << level << std::endl; 
    std::vector<int>::iterator start = aa.begin();
    std::vector<int>::iterator end = aa.end();
    end -= aa.size() - (level * pair_units_nbr);
    if (pair_units_nbr % 2 == 1){
        int move_end = level;
        end -= move_end;
        std::cout << "Odd, level: " << level << " number is: " << *end << "move end is: " << move_end << std::endl;
    }
    std::cout << "Not Odd, level: " << level << " number is: " << *end << std::endl;
    for (auto it = start; it != end; it += (2*level))
    {
        std::cout << *(it + level - 1) << " " << *(it+level * 2 - 1) << std::endl;
        if (*(it + level -1) > *(it+level * 2 - 1))
        {
            //std::iter_swap((it + level - 1), (it+level * 2 - 1));
            _swap_pair((it + level - 1),level);

            std::cout << "SWAPPING" << std::endl;
        }
    }  

    //(void)level;
    std::cout << "Entering next level" << std::endl;
    merge_insertion_sort(aa, level * 2);
    std::list<std::vector<int>::iterator> main = { start, start + 2*level};
    
    for (auto it = main.begin(); it != main.end(); ++it){
        std::cout << **it << " ";
    }
}
    
