#include "Array.hpp"

template <class T>
Array<T>::Array() : _size(0), _array(new T[0]) {}

template <class T>
Array<T>::Array(unsigned int size) :  _size(size), _array(nullptr){
	_array = new T[size];
}

template <class T>
Array<T>::Array(const Array<T> &copy) : _size(copy._size), _array(new T[copy._size]) {
		for (size_t i = 0; i < copy._size; i++)
			_array[i] = copy._array[i];
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs){
	if (this != &rhs){
		T* newArray = new T[rhs._size];
		for (size_t i = 0; i < rhs._size; i++)
			newArray[i] = rhs._array[i];
		delete [] _array;
		_array = newArray;
		_size = rhs._size;
	}
	return (*this);
}

template <class T>
const T &Array<T>::operator[](size_t index) const 
{
	 if (index >= _size)
	 	throw(std::runtime_error("Index is out of bounds."));
	return _array[index];
}

template <class T>
T &Array<T>::operator[](size_t index)
{
	 if (index >= _size)
	 	throw(std::runtime_error("Index is out of bounds."));
	return _array[index];
}

template <class T>
Array<T>::~Array(){
	delete [] _array;
}

template <class T>
size_t Array<T>::size() const {
	return (_size);
}
