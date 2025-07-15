#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iterator>
#include <stdexcept>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &haystack, const int &needle){
	auto it = std::find(haystack.begin(),haystack.end(), needle);
	if (it != haystack.end())
		return (it);
	throw std::runtime_error("Integer not found in the container");
}

template <typename T>
typename T::const_iterator easyfind(const T &haystack, const int &needle){
	auto it = std::find(haystack.begin(),haystack.end(), needle);
	if (it != haystack.end())
		return (it);
	throw std::runtime_error("Integer not found in the container");
}

#endif