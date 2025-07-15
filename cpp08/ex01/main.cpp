#include "Span.hpp"
#include <iostream>
#include <vector>
#include <array>

int main()
{	
	try{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;}
	catch(std::runtime_error &e){
		std::cerr << e.what() << std::endl;}

	std::cout << "Fill the giga Span" << std::endl;
	try{

		Span sp2 = Span(10000);

		std::vector<int> test;
		srand(time(NULL));
		for (int i = 0; i < 10000; i++){
			test.push_back(rand());
		}

		sp2.FillSpan(test.begin(), test.end());

		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;

	} catch(std::runtime_error &e){
		std::cerr << e.what() << std::endl;}
	return 0;
}