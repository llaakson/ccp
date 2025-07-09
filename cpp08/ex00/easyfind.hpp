#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>

template <typename T>
typename T::iterator easyfind(T &haystack, const int &needle){
	for (typename T::iterator it = haystack.begin(); it != haystack.end(); ++it){
		if (*it == needle)
			return(it);
	}
	throw std::runtime_error("Integer not found in the container");
}

#endif