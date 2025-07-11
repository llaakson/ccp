#include "Span.hpp"
#include <iostream>
#include <vector>
#include <array>

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
		for (int i = 0; i < 10; i++){
			test.push_back(rand());
		}
		
		Span sp2 = Span(10);
		//sp2.addNumber(13);
		sp2.FillSpan(test.begin(), test.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	} catch(std::runtime_error &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::array<int, 5> int_array = {99, 0, -1, 1, 101};
		Span sp3 = Span(10);
		//sp2.addNumber(13);
		sp3.FillSpan(int_array.begin(), int_array.end());
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	} catch(std::runtime_error &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
	//test.insert();
}