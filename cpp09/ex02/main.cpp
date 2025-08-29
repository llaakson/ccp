#include "PmergeMe.hpp"

int main()
{
    class PmergeMe Pmerge;

    std::vector<int> basic = {11,2,17,0,16,8,6,15,10,3,21,1,18,9,14,19,12,5,4,20,13,7};
    Pmerge.start(basic,1);

    // std::vector<int> basic1 = {5,4,3,2,1};
    // Pmerge.start(basic1,1);
    // std::vector<int> basic2 = {1,2,3,4,5};
    // Pmerge.start(basic2,1);
    // std::vector<int> basic33 = {3,2,1,99};
    // Pmerge.start(basic33,1);
    // std::vector<int> basic3 = {3,2,1};
    // Pmerge.start(basic3,1);
    // std::vector<int> basic4 = {3,2};
    // Pmerge.start(basic4,1);
    //  std::vector<int> basic5 = {3};
    // Pmerge.start(basic5,1);

    return 0;
}