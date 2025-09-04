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

void PmergeMe::create_temp_pend(std::vector<int> &temp_pend, int level, int jacob,int shit,int flag){

    _temp_pend.clear();
    //(void)shit;
    int i = 2;
    if (level == 1 && flag == 1){
        _temp_pend.insert(_temp_pend.begin(), temp_pend.begin(), temp_pend.begin()  + shit);
          std::cout << "Created temp main"  << std::endl;
         for (auto it = _temp_pend.begin(); it != _temp_pend.end(); it++){
        std::cout << *it << " ";
    }
        return ;
    }
    if (level == 1 && flag == 0){
        //_temp_pend = temp_pend;
        _temp_pend.insert(_temp_pend.begin(), temp_pend.begin(), temp_pend.begin() + jacob);
          std::cout << "Created temp main"  << std::endl;
         for (auto it = _temp_pend.begin(); it != _temp_pend.end(); it++){
        std::cout << *it << " ";}
        return ;
    }
    for (auto it = temp_pend.begin(); it != temp_pend.end(); it++){
        if (i % level == 1)
            _temp_pend.push_back(*it);
        i++;
        if ((int)_temp_pend.size() == jacob)
            break;
    }
    std::cout << "Created temp main"  << std::endl;
    for (auto it = _temp_pend.begin(); it != _temp_pend.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::vector<int>::iterator PmergeMe::find_insert_position(std::vector<int> &main, int position){
    for (auto it = main.begin(); it != main.end(); it++)
    {
        if (*it == position){
            //it++;
            return it;
        }
    }
    return main.end();
}

void PmergeMe::start(std::vector<int> &container, int _level){
 
    if (container.size() / _level < 2) // Here to stop recursion
        return;
    bool odd = container.size() / _level % 2 == 1;
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
    auto stored_pends = 0;
    int shit = 0;
    auto previous_jacobs_num = jacobsthal_number(1);
    for (long k = 2; ;++k)
    {
        auto jacobs_num = jacobsthal_number(k);
        auto number_of_pends = jacobs_num - previous_jacobs_num;
        if (number_of_pends > (long)pend.size())
        {
            shit = pend.size() - 1;
            int tit = pend.size();
            while (pend.size())
            {
                auto pend_position2 = pend.end();
                pend_position2--;
                create_temp_pend(main,_level,jacobs_num+stored_pends,(main.size() - tit+shit+odd),1);
                auto main_insert_position2 = std::upper_bound(_temp_pend.begin(),_temp_pend.end(),*pend_position2,[&](int a, int b) {comparison++; return a < b; });
                if (main_insert_position2 == _temp_pend.end()){
                    main_insert_position2 = main.begin()+(_temp_pend.size()*_level);}
                else{
                    main_insert_position2 = find_insert_position(main, *main_insert_position2);
                if (main_insert_position2 != main.end() && main_insert_position2 != main.begin())
                {
                    if (std::distance(main.begin(),main_insert_position2) < _level-1)
                        main_insert_position2 = main.begin();
                    else
                        main_insert_position2 -= _level-1;
                }}
                 std::cout << "Leftovers: pend number is: " << *pend_position2 << " main insert position: " << *main_insert_position2 << std::endl;
                main.insert(main_insert_position2, pend.end()-_level, pend.end());
                pend.erase(pend.end()-_level,pend.end());
                //if (_level == 1)
                shit--;
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
            std::cout << "ASDA" << stored_pends << std::endl;
            create_temp_pend(main,_level,jacobs_num+stored_pends,shit,0);
            std::cout << " pend number is: " << *pend_position << " Main END: " << *(main.begin()+(jacobs_num*_level+aa)) << " Jacobs number: " << jacobs_num*_level+aa <<std::endl;
            if (jacobs_num*_level+aa > (int)main.size()){
                std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
                break;}
            auto main_insert_position = std::upper_bound(_temp_pend.begin(),_temp_pend.end(),*pend_position,[&](int a, int b) { comparison++; return a < b; });
            std::cout << "Upper bound returned: " << *main_insert_position << std::endl;
            if (main_insert_position == _temp_pend.end()){
                main_insert_position = main.begin()+(_temp_pend.size()*_level);
                //main_insert_position -= _level-1;
                stored_pends--;
                std::cout << "AAAAAAAAAAAAAAA"  << std::endl;
            }
            else{
                main_insert_position = find_insert_position(main, *main_insert_position);
            std::cout << "Upper bound returned: " << *main_insert_position << std::endl;
            if (main_insert_position != main.begin()+(jacobs_num*_level+aa) && main_insert_position != main.begin()){ //might need aa
                if (std::distance(main.begin(),main_insert_position) < _level-1)
                    main_insert_position = main.begin();
                else
                    main_insert_position -= _level-1;}}
            std::cout << "Jacob nummber: " << jacobs_num << " pend number is: " << *pend_position 
            << " main insert position: " << *(main_insert_position)<< std::endl;
            main.insert(main_insert_position, pend_position - _level + 1, pend_position + 1);
            auto erase_start = pend_position - _level + 1;
            auto erase_end = pend_position + 1;
            pend.erase(erase_start, erase_end);
            std::cout << "Pending to main" << std::endl;

            number_of_pends--;
            //previous_jacobs_num = jacobs_num;
            std::cout << "MAIN: " << _level << " : ";
            for (auto it = main.begin(); it != main.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
            std::cout << "PEND: " << _level << " : ";
            for (auto it = pend.begin(); it != pend.end(); ++it){std::cout << *it << " ";}std::cout << "\n";    
        }
        stored_pends = jacobs_num - previous_jacobs_num;
        previous_jacobs_num = jacobs_num;
        aa = jacobs_num - previous_jacobs_num * _level;
    }}

    main.insert(main.end(), extra.begin(), extra.end());
    std::cout << "After Jacobs magic" << std::endl;
    std::cout << "MAIN: " << _level << " : ";
    for (auto it = main.begin(); it != main.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
    std::cout << "PEND: " << _level << " : ";
    for (auto it = pend.begin(); it != pend.end(); ++it){std::cout << *it << " ";}std::cout << "\n";

    container = main;
    std::cout << "COOOOOOOOOOOMP: " << comparison << std::endl;

    return ;
}
