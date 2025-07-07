#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
	private:
		size_t _size;
		T *_array;
	public:
		Array();
		Array(unsigned int size);
		Array(const Array<T> &copy);
		Array<T> &operator=(const Array<T> &rhs);
		~Array();

		const T& operator[](size_t index) const;
		T& operator[](size_t index);
		size_t size() const;
};

#include "Array.tpp"

#endif