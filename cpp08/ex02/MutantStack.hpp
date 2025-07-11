#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK__HPP

#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>{
    private:

    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack<T>& operator=(const MutantStack<T> &rhs);

        iterator begin();
        iterator end();

};

#endif