#include "MutantStack.hpp"
#include <iostream>
#include <iterator>
#include <list>

int main()
{
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
    //std::stack<int> s(liststack);
    }
    return 0;
}