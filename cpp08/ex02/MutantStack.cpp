#include "MutantStack.hpp"
#include <iterator>

template<typename T>
MutantStack<T>::MutantStack(){}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &copy){}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &rhs){}

template<typename T>
iterator MutantStack<T>::begin();

template<typename T>
iterator MutantStack<T>::end();
