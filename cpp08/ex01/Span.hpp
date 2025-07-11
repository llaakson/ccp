#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <iostream>

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
		unsigned int shortestSpan();
		unsigned int longestSpan();

		template <typename T>
		void FillSpan(T start, T end){
			unsigned int distance = std::distance(start,end);
			if (distance + _v.size() > _N)
				throw std::runtime_error("Span is full");
			_v.insert(_v.begin(), start, end);
			std::cout << "Printing the list of size: " << distance << std::endl;
			for (auto it = _v.begin(); it != _v.end(); ++it){
				std::cout << *it << std::endl;
			}
			std::cout << "End of list" << std::endl;}
 };

#endif