#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void ft_print_array(T x){
		std::cout << x << std::endl;
}

template <typename T1> void iter(T1 *ptr, size_t size, void(function(T1 &))){
	for (size_t i = 0; i < size; i++){
		(function)(ptr[i]);
	}
}

#endif