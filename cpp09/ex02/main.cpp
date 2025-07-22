#include "PmergeMe.hpp"

int main(int argc, char **argv){
     if (argc < 1)
         return 1;
    PmergeMe merge;
    merge.start_merging(argc,argv); 

    return 0;
}