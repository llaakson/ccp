#include "MutantStack.hpp"
#include <iostream>
#include <iterator>
#include <list>

int main()
{
    try{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "-----Same tests with list-----" << std::endl;
        std::list<int> liststack;
        liststack.push_back(5);
        liststack.push_back(17);
        std::cout << liststack.back() << std::endl;
        liststack.pop_back();
        std::cout << liststack.size() << std::endl;
        liststack.push_back(3);
        liststack.push_back(5);
        liststack.push_back(737);
        //[...]
        liststack.push_back(0);
        auto it = liststack.begin();
        auto ite = liststack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    {
        std::cout << "-----Iterator action-----" << std::endl;
        std::cout << "-----Reverse iterator-----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(42);
        mstack.push(-42);
        mstack.push(999);
        mstack.push(0);
        mstack.push(420);
        MutantStack<int>::reverse_iterator it = mstack.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack.rend();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout << "-----Const Reverse iterator-----" << std::endl;
        const MutantStack<int> const_mstack(mstack);
        MutantStack<int>::const_reverse_iterator it_const = const_mstack.rbegin();
        MutantStack<int>::const_reverse_iterator ite_const = const_mstack.rend();
        while (it_const != ite_const)
        {
            std::cout << *it_const << std::endl;
            ++it_const;
        }

        std::cout << "-----Const iterator-----" << std::endl;
        const MutantStack<int> const_const_mstack(mstack);
        MutantStack<int>::const_iterator it_const_const = const_const_mstack.begin();
        MutantStack<int>::const_iterator ite_const_const = const_const_mstack.end();
        while (it_const_const != ite_const_const)
        {
            std::cout << *it_const_const << std::endl;
            ++it_const_const;
        }
    }} catch(...){
        std::cerr << "Something went wrong" << std::endl;
    }
    return 0;
}