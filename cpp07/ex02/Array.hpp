#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
	public:
		int *_poop;
		int _size;

		Array(){
			_poop = new int[0];
		}
		Array(T size){
			_poop = new int[size];
			for (int i = 0; i < size; i++)
				_poop[i] = 1;
			_size = size;
		}

		T& operator[](int);
		~Array();
		size_t size();
};

#endif