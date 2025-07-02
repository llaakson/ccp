#include "Array.hpp"

template <class T>
T &Array<T>::operator[](int index)
{
	 if (index >= _size)
	 	throw(std::runtime_error("Index is out of bounds."));
	return _poop[index];
}

template <class T>
Array<T>::~Array(){
	// for (int i = 0; i < _size; i++){
	// 	delete _poop[i];
	// }
	delete [] _poop;
}

template <class T>
size_t Array<T>::size(){
	return (_size);
}
