#pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <iterator>

class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(PmergeMe &copy) = delete;
        PmergeMe& operator=(PmergeMe &rhs) = delete;
        long jacobsthal_number(long n);

        template <typename T>
        void create_temp_pend(T &temp_pend, int level, int jacob,int pendsize,int flag, T &_temp_pend)
        {
            _temp_pend.clear();
            int i = 2;
            if (level == 1 && flag == 1){
                _temp_pend.insert(_temp_pend.begin(), temp_pend.begin(), temp_pend.begin()  + pendsize);
                return ;
            }
            if (level == 1 && flag == 0){
                _temp_pend.insert(_temp_pend.begin(), temp_pend.begin(), temp_pend.begin() + jacob);
                return ;
            }
            for (auto it = temp_pend.begin(); it != temp_pend.end(); it++){
                if (i % level == 1)
                    _temp_pend.push_back(*it);
                i++;
                if ((int)_temp_pend.size() == jacob)
                    break;
            }
        }

        template <typename T>
        typename T::iterator find_insert_position(T &main, int position, int level){
        for (auto it = main.begin(); it != main.end(); it++)
        {
            if (*it == position && std::distance(main.begin(),it) % level == level -1 ){
                return it;
            }
        }
        return main.end();
        }

        template <typename T>
        void start(T &container, int level){
    
        if (container.size() / level < 2) // Here to stop recursion
            return;
        bool odd = container.size() / level % 2 == 1;
        auto end = container.end();
        end -= container.size() - (level * (container.size() / level));
        if (container.size() / level % 2 == 1){
            int move_end = level;
            end -= move_end;
        }
        
        for (auto it = container.begin(); it != end; it = std::next(it, 2 * level))
        {
            if (*std::next(it, level - 1) > *std::next(it, level * 2 - 1))
            {
                auto first = std::next(it, level - 1);
                for(int i = level; i != 0; i--){
                std::iter_swap(first, next(first, level));
                first--;
                }
            }
        }  
        start(container, level * 2); // recursio with increased level
        T main, pend, extra, _temp_pend;
        //Put b1 and a1 to main
        main.insert(main.begin(), container.begin(), std::next(container.begin(),level *2));
        unsigned long i = 2; 
        // Adding pend and main
        while(i < container.size() / level)
        {
            unsigned long start_position = level * i;
            if (i % 2 == 1)
                main.insert(main.end(), std::next(container.begin(),start_position), std::next(container.begin(),start_position + level));
            else
                pend.insert(pend.end(), std::next(container.begin(),start_position), std::next(container.begin(),start_position + level));
            i++;
        }
        // Making extra
        if ((i * level) <= container.size())
            extra.insert(extra.begin(), std::next(container.begin(),i * level), container.end());
        // ---------------Jacob-------------------
        if (pend.size() > 0){
        int index = 0;
        auto stored_pends = 0;
        int pendsize = 0;
        auto previous_jacobs_num = jacobsthal_number(1);
        for (long k = 2; ;++k)
        {
            auto jacobs_num = jacobsthal_number(k);
            auto number_of_pends = jacobs_num - previous_jacobs_num;
            if (number_of_pends > (long)pend.size())
            {
                pendsize = pend.size() - 1;
                int stored_pendsize = pend.size();
                while (pend.size())
                {
                    auto pend_position2 = pend.end();
                    pend_position2 = std::prev(pend_position2,1);
                    create_temp_pend(main,level,jacobs_num+stored_pends,(main.size() - stored_pendsize+pendsize+odd),1, _temp_pend);
                    auto main_insert_position2 = std::upper_bound(_temp_pend.begin(),_temp_pend.end(),*pend_position2,[&](int a, int b) {return a < b; });
                    if (main_insert_position2 == _temp_pend.end()){
                        main_insert_position2 = std::next(main.begin(),_temp_pend.size()*level);
                    }
                    else{
                        main_insert_position2 = find_insert_position(main, *main_insert_position2, level);
                    if (main_insert_position2 != main.end() && main_insert_position2 != main.begin())
                    {
                        if (std::distance(main.begin(),main_insert_position2) < level-1)
                            main_insert_position2 = main.begin();
                        else
                            main_insert_position2 = std::prev(main_insert_position2,level-1);
                    }}
                    main.insert(main_insert_position2, std::prev(pend.end(),level), pend.end());
                    pend.erase(std::prev(pend.end(),level),pend.end());
                    pendsize--;
                }
                break;
            }
            // Find the correct value from pend vector
            while(number_of_pends){
                if (number_of_pends * level -1 > (int)pend.size())
                    break;
                auto pend_position = pend.begin();
                pend_position = std::next(pend_position, number_of_pends * level -1);
                //Find the correct position in main where to insert
                // Upper bound uses custom comparator
                create_temp_pend(main,level,jacobs_num+stored_pends,pendsize,0, _temp_pend);
                if (jacobs_num*level+index > (int)main.size()){
                    break;}
                auto main_insert_position = std::upper_bound(_temp_pend.begin(),_temp_pend.end(),*pend_position,[&](int a, int b) {return a < b; });
                if (main_insert_position == _temp_pend.end())
                {
                    main_insert_position = std::next(main.begin(),_temp_pend.size()*level);
                }
                else{
                    main_insert_position = find_insert_position(main, *main_insert_position, level);
                if (main_insert_position != std::prev(_temp_pend.end(),1) && main_insert_position != main.begin()){ 
                    if (std::distance(main.begin(),main_insert_position) < level-1)
                        main_insert_position = main.begin();
                    else
                        main_insert_position = std::prev(main_insert_position,level-1);
                    }
                }
                main.insert(main_insert_position, std::prev(pend_position,level - 1), std::next(pend_position,1));
                auto erase_start = std::prev(pend_position,level - 1);
                auto erase_end = std::next(pend_position,1);
                pend.erase(erase_start, erase_end);
                number_of_pends--;
            }
            stored_pends += jacobs_num - previous_jacobs_num;
            previous_jacobs_num = jacobs_num;
            index = jacobs_num - previous_jacobs_num * level;
        }}
        main.insert(main.end(), extra.begin(), extra.end());
        container = main;
        return ;
        }

};
