#include "Span.hpp"
#include <algorithm>

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {
	
}
Span::~Span(){}

Span::Span(const Span &copy) : _N(copy._N) {}

Span& Span::operator=(const Span &rhs){
	if (this != &rhs)
		return *this;
	return *this;
}

void Span::addNumber(unsigned int n){
	if (_v.size() == _N)
		throw std::runtime_error("Span is full");
	_v.push_back(n);	
}

unsigned int Span::shortestSpan(){
	if (_v.size() < 2)
		throw std::runtime_error("Span has less than two elements");
	
	std::sort(_v.begin(), _v.end());
	unsigned int result = _v[1] - _v[0];
	unsigned int temp = 0;
	for (unsigned int i = 2; i < _v.size(); i++){
		temp = _v[i] - _v[i-1];
		//std::cout << temp << std::endl;
		if (temp < result)
			result = temp;
	}
	return (result);
}
unsigned int Span::longestSpan(){
	if (_v.size() < 2)
		throw std::runtime_error("Span has less than two elements");
	
	int max_val = *std::max_element(_v.begin(), _v.end());
	int min_val = *std::min_element(_v.begin(), _v.end());
	return (max_val - min_val);
}
// template <typename T>
// void Span::FillSpan(T start, T end){
// 	unsigned int distance = std::distance(start,end);
// 	if (distance + _v.size() > _N)
// 		throw std::runtime_error("Span is full");
// 	_v.insert(_v.begin(), start, end);
// 	std::cout << "Printing the list of size: " << distance << std::endl;
// 	for (auto it = _v.begin(); it != _v.end(); ++it){
// 		std::cout << *it << std::endl;
// 	}
// 	std::cout << "End of list" << std::endl;
// }