#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe &copy){
    (void)copy;
}

PmergeMe& PmergeMe::operator=(PmergeMe &rhs){
    (void)rhs;
    return *this;
}

long PmergeMe::jacobsthal_number(long n) { return round((pow(2, n + 1) + pow(-1, n)) / 3);}

bool cmp(const std::vector<int>::iterator& a, const std::vector<int>::iterator& b) {return *a < *b;};

void PmergeMe::start(std::vector<int> &container, int _level){
    for (auto it = container.begin(); it != container.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
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
            //std::cout << "SWAPPING" << std::endl;
            auto first = (it + _level -1);
            //auto second = (it + _level * 2 - 1);
            for(int i = _level; i != 0; i--){
            std::iter_swap(first, next(first, _level));
               first--;
            }
        }
    }  
    std::cout << std::endl;
    start(container, _level * 2); // recursio with increased level
    std::list<std::vector<int>::iterator> main;
    std::list<std::vector<int>::iterator> pend;

    std::cout << "Making main" << std::endl;
    for (auto it = container.begin(); it != container.begin() + _level * 2; ++it){
        main.push_back(it);
    }
    // add rest
    //std::cout << "Adding rest to the main" << std::endl;
    int c = 0;
    if ((size_t)std::distance(container.begin(), end + _level) < container.size())
        end += _level;
    if (_level == 1 && container.size() > 3)
        end--;
    //std::cout << "Adding pend" << std::endl;
    for (auto it = container.begin() + _level * 2; it != end; ++it)
    {
        if (c >= _level)
            main.push_back(it);
        else
            pend.push_back(it);
        c++;
        if (c == 2 * _level)
            c = 0;
    }
    if (container.size() / _level % 2 == 1)
        for (auto it = end; it != container.end(); ++it)
            pend.push_back(it);

    std::cout << "LEVEL: " << _level << " : ";
    for (auto it = container.begin(); it != container.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
    std::cout << "MAIN: " << _level << " : ";
    for (auto it = main.begin(); it != main.end(); ++it){std::cout << **it << " ";}std::cout << "\n";
    std::cout << "PEND: " << _level << " : ";
    for (auto it = pend.begin(); it != pend.end(); ++it){std::cout << **it << " ";}std::cout << "\n";

    auto old_jacob = jacobsthal_number(1);
    int main_helper = 0;
    for (long k = 2; ; ++k)
    {
        // Find next index
        auto distance = jacobsthal_number(k);
        auto number_of_pends = distance - old_jacob;
        if (distance > (long)pend.size()) // stop the loop
            break;
        auto it = pend.begin();

        std::advance(it, number_of_pends * _level - 1); // <- what we should append to the main fron pend
        //it += (int)distance; // move iterator to correct position;
        std::cout << "Jacob nummber: " << distance << " pend number is: " << **it << std::endl;
        while(number_of_pends){
            // std::cout << "Insertion start: " << number_of_pends << " pend number is: " << **it << std::endl;
            // for (auto it = pend.begin(); it != pend.end(); ++it){std::cout << **it << " ";}std::cout << "\n";
            // for (auto it = main.begin(); it != main.end(); ++it){std::cout << **it << " ";}std::cout << "\n";
            auto start_pos = pend.begin();
            if (number_of_pends != 1)
                std::advance(start_pos, _level); // need to advance based on number of pends ??
            //find the insertion place
            auto main_end = main.end();
            std::advance(main_end, main_helper);
            auto aa = std::upper_bound(main.begin(),main_end,*it,cmp);
            std::advance(aa,-_level+1);
            it++;
            //std::cout << "MAIN: " << **aa << " START: " << **start_pos << " END: " << **it << std::endl;
            main.insert(aa, start_pos, it);
            //std::cout << "Insertion done" << std::endl;
            for (int i = 0; i < _level; i++){
                start_pos = pend.erase(start_pos);
            }
            it = start_pos;
            it--;
            number_of_pends--;
            main_helper = -1 * number_of_pends;
        }
        old_jacob = distance;
        std::cout << "Getting new number" << std::endl;
    }
    std::cout << "Done with Jacob" << std::endl;
    main.insert(main.end(), pend.begin(), pend.end());
    for (auto it = main.begin(); it != main.end(); ++it){std::cout << **it << " ";}std::cout << "\n";

    //int u = 0;
    std::vector<int> copy;
    for (auto it = main.begin(); it != main.end(); ++it)
    {
        //copy.push_back(*it);
        copy.push_back(**it);
        std::cout << "going in copyyyyyyyyyyyyyy "<<**it << std::endl;
        //u++;
        // for (int i = 0; i < _level; i++)
        // {
        //     auto pair_start = *it;
        //     std::advance(pair_start, -_level + i + 1);
        //     copy.insert(copy.end(), **it, pair_start);
        // }
    }
    std::cout << "COPYYYYYYYYYYYYYYYYYYYY" << std::endl;
    for (auto it = copy.begin(); it != copy.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
    

    
    // int u = 0;
    // for (auto it = container.begin(); it != container.end(); ++it){
    //     container[u] = *it;
    //     u++;
    // }

    auto original_container = container.begin();
    auto main_copy = copy.begin();
    while (main_copy != copy.end())
    {
        std::cout << "Original container: " << *original_container << "  copy amin: " << *main_copy << std::endl;
        *original_container = *main_copy;
        original_container++;
        main_copy++;
    }
    return ;
}

       // auto main_start = main.begin();
            // for (size_t i = 0; i < pend.size(); i += _level)
            // {
            //     std::advance(main_start, _level);
            //     if (i == 0)
            //         std::advance(main_start,-1);
            //     std::cout << "main_start: " << **main_start << " start pos: " << **it << std::endl;
            //     if (**main_start > **it){
            //         main_start++;
            //         break;}
            // }
