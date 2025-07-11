#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>

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
		void FillSpan(std::vector<int>::iterator start, std::vector<int>::iterator end);
		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif