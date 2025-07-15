#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

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
        //stack<T> defautls to deque so you can use all of its iterators
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator begin(){return this->c.begin();}
        iterator end(){return this->c.end();}
        const_iterator begin() const {return this->c.begin();}
        const_iterator end() const{return this->c.end();}
        reverse_iterator rbegin() { return this->c.rbegin(); }
        reverse_iterator rend() { return this->c.rend(); }
        const_reverse_iterator rbegin() const { return this->c.rbegin(); }
        const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif