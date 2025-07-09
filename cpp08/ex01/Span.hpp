#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

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
		void FillSpan();
		unsigned int shortestSpan();
		unsigned int longestSpan();
};

#endif