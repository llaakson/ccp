#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try{
		std::vector<int> test;
		for (int i = 0; i < 10000; i++){
			test.push_back(rand());
		}
		
		Span sp2 = Span(10000);
		sp2.FillSpan(test.begin(), test.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	} catch(std::runtime_error &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
	//test.insert();
}