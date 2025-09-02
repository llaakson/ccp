#include "PmergeMe.hpp"

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

template <typename T>
bool cmp(T &a, T &b) {return a < b;};

void PmergeMe::start(std::vector<int> &container, int _level){
 
    if (container.size() / _level < 2) // Here to stop recursion
        return;
    
    auto end = container.end();
    end -= container.size() - (_level * (container.size() / _level));
    if (container.size() / _level % 2 == 1){
        int move_end = _level;
        end -= move_end;
    }
    
    for (auto it = container.begin(); it != end; it += (2 * _level))
    {
        //std::cout << *(it + _level - 1) << " " << *(it + _level * 2 - 1) << std::endl;
        if (*(it + _level -1) > *(it + _level * 2 - 1))
        {
            auto first = (it + _level -1);
            //auto second = (it + _level * 2 - 1);
            for(int i = _level; i != 0; i--){
            std::iter_swap(first, next(first, _level));
               first--;
            }
        }
        comparison++;
    }  
    std::cout << std::endl;
    start(container, _level * 2); // recursio with increased level
    std::vector<int> main, pend, extra;
    std::cout << "Making main" << std::endl;
    //Put b1 and a1 to main

    main.insert(main.begin(), container.begin(), container.begin() + _level *2);
    unsigned long i = 2; 
    // Adding pend and main
    while(i < container.size() / _level)
    {
        unsigned long start_position = _level * i;
        if (i % 2 == 1)
            main.insert(main.end(), container.begin() + start_position, container.begin() + start_position + _level);
        else
            pend.insert(pend.end(), container.begin() + start_position, container.begin() + start_position + _level);
        i++;
    }
    // Making extra
    if ((i * _level) <= container.size())
        extra.insert(extra.begin(), container.begin() + i * _level, container.end());
    
     std::cout << "-----------------LEVEL: -----------" << _level << " : ";
    for (auto it = container.begin(); it != container.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
    std::cout << "MAIN: " << _level << " : ";
    for (auto it = main.begin(); it != main.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
    std::cout << "PEND: " << _level << " : ";
    for (auto it = pend.begin(); it != pend.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
    std::cout << "EXTRA: " << _level << " : ";
    for (auto it = extra.begin(); it != extra.end(); ++it){std::cout << *it << " ";}std::cout << "\n";

    // ---------------Jacob-------------------
    if (pend.size() > 0){
    int aa = 0;
    auto previous_jacobs_num = jacobsthal_number(1);
    for (long k = 2; ;++k)
    {
        auto jacobs_num = jacobsthal_number(k);
        auto number_of_pends = jacobs_num - previous_jacobs_num;
        if (jacobs_num > (long)pend.size())
        {
            while (pend.size())
            {
                auto pend_position2 = pend.end();
                pend_position2--;
                auto main_insert_position2 = std::upper_bound(main.begin(),main.end(),*pend_position2,[](int a, int b) { return a < b; });
                std::cout << "Leftovers: pend number is: " << *pend_position2 << " main insert position: " << *main_insert_position2 << std::endl;
                // if (main_insert_position2 != main.end() && main_insert_position2 != main.begin())
                // {
                //     if (std::distance(main.begin(),main_insert_position2) < _level-1)
                //         main_insert_position2 = main.begin();
                //     else
                //         main_insert_position2 -= _level-1;
                // }
                main.insert(main_insert_position2, pend.end()-_level, pend.end());
                pend.erase(pend.end()-_level,pend.end());
            }
            break;
        }
        // Find the correct value from pend vector
        //std::cout << "Jacob nummber: " << jacobs_num << " pend number is: " << *pend_position << std::endl;
        while(number_of_pends){
            if (number_of_pends * _level -1 > (int)pend.size())
                break;
            auto pend_position = pend.begin();
            pend_position += number_of_pends * _level -1;
            //Find the correct position in main where to insert
            // Upper bound uses custom comparator
            std::cout << " pend number is: " << *pend_position << " Main END: " << *(main.begin()+(jacobs_num*_level+aa)) << std::endl;
            if (jacobs_num*_level+aa > (int)main.size()){
                std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
                break;}
            auto main_insert_position = std::upper_bound(main.begin(),main.begin()+(jacobs_num*_level+aa),*pend_position,[](int a, int b) { return a < b; });
             std::cout << "Upper bound returned: " << *main_insert_position << " Limits: " << *(main.begin()) << " and " << *(main.begin()+(jacobs_num*_level+aa))<< std::endl; // might need aa
            // if (main_insert_position != main.begin()){
            //     main_insert_position -= _level-1;
            // }
            if (main_insert_position != main.begin()+(jacobs_num*_level+aa) && main_insert_position != main.begin()){ //might need aa
                if (std::distance(main.begin(),main_insert_position) < _level-1)
                    main_insert_position = main.begin();
                else
                    main_insert_position -= _level-1;}
            // std::cout << "Jacob nummber: " << jacobs_num << " pend number is: " << *pend_position 
            // << " main insert position: " << *(main_insert_position)<< std::endl;
            main.insert(main_insert_position, pend_position - _level + 1, pend_position + 1);
            auto erase_start = pend_position - _level + 1;
            auto erase_end = pend_position + 1;
            pend.erase(erase_start, erase_end);
            std::cout << "Pending to main" << std::endl;

            //pend_position -= _level;
            number_of_pends--;
            previous_jacobs_num = jacobs_num;

                // for (auto it = container.begin(); it != container.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
                std::cout << "MAIN: " << _level << " : ";
                for (auto it = main.begin(); it != main.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
                std::cout << "PEND: " << _level << " : ";
                for (auto it = pend.begin(); it != pend.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
                // std::cout << "EXTRA: " << _level << " : ";
                // for (auto it = extra.begin(); it != extra.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
        }
        aa = jacobs_num - previous_jacobs_num * _level;
    }}

    main.insert(main.end(), extra.begin(), extra.end());
    std::cout << "After Jacobs magic" << std::endl;
    std::cout << "MAIN: " << _level << " : ";
    for (auto it = main.begin(); it != main.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
    std::cout << "PEND: " << _level << " : ";
    for (auto it = pend.begin(); it != pend.end(); ++it){std::cout << *it << " ";}std::cout << "\n";

    container = main;

    return ;
}
