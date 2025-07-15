#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _v;
	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span &copy);
		Span& operator=(const Span &rhs);

		void addNumber(unsigned int n);
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		template <typename T>
		void FillSpan(T start, T end){
			unsigned int distance = std::distance(start,end);
			if (distance + _v.size() > _N)
				throw std::runtime_error("Span can't hold all these integers!");
			_v.insert(_v.end(), start, end);}
 };

#endif