#include "PmergeMe.hpp"

int main(){

    class PmergeMe merger;
    std::vector<int> basic = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};
    merger.merge_insertion_sort(basic,1);

    return 0;
}