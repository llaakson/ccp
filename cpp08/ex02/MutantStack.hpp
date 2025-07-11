#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>{
    private:

    public:
        MutantStack() : std::stack<T>(){}
        ~MutantStack(){}
        MutantStack(const MutantStack &copy) : std::stack<T>(copy){}
        MutantStack<T>& operator=(const MutantStack<T> &rhs){
            if (this != &rhs)
                std::stack<T>::operator=(rhs);
            return *this;
        }

        //container_type is a typedef inside std::stack that tells you what the underlying container is.
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin(){return this->c.begin();}
        iterator end(){return this->c.end();}
};

#endif