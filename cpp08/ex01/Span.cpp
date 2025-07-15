#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::~Span(){}

Span::Span(const Span &copy) : _N(copy._N), _v(copy._v) {}

Span& Span::operator=(const Span &rhs){
	if (this != &rhs){
		_N = rhs._N;
		_v = rhs._v;
	}
	return *this;
}

void Span::addNumber(unsigned int n){
	if (_v.size() == _N)
		throw std::runtime_error("Span is full");
	_v.push_back(n);	
}

unsigned int Span::shortestSpan() const {
	if (_v.size() < 2)
		throw std::runtime_error("Span has less than two elements");
	std::vector<int> temp_v = _v;	
	std::sort(temp_v.begin(), temp_v.end());
	unsigned int result = temp_v[1] - temp_v[0];
	unsigned int temp = 0;
	for (unsigned int i = 2; i < temp_v.size(); i++){
		temp = temp_v[i] - temp_v[i-1];
		if (temp < result)
			result = temp;
	}
	return (result);
}
unsigned int Span::longestSpan() const {
	if (_v.size() < 2)
		throw std::runtime_error("Span has less than two elements");
	int max_val = *std::max_element(_v.begin(), _v.end());
	int min_val = *std::min_element(_v.begin(), _v.end());
	return (max_val - min_val);
}