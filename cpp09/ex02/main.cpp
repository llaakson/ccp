#include "PmergeMe.hpp"

int main(int argc, char **argv){
     if (argc < 1)
         return 1;
    std::vector<int> temp;
    for (int i = 1; argc > i; i++){
        temp.push_back(atoi(argv[i]));
    }
    std::cout << "main list" << std::endl;
    for (auto it = temp.begin(); it != temp.end(); ++it){
        std::cout << *it << std::endl;}
    PmergeMe merge;
    merge.start_merging(temp); 

    return 0;
}