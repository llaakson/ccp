#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <forward_list>

int main(void){
	try{
	std::array<int, 5> int_array = {99, 0, -1, 1, 101};
	std::vector<int> int_vector = {1, 2, 42, 0};
	std::deque<int> int_deque = {1,2,42,0};
	std::list<int> int_list = {1,2,42,0};
	std::forward_list<int> int_forward_list = {1,2,42,0};

	auto result3 = easyfind(int_array,101);
	std::cout << result3 << std::endl;
	auto result = easyfind(int_vector,42);
	std::cout << *result << std::endl;
	auto result2 = easyfind(int_deque,42);
	std::cout << *result2 << std::endl;
	std::vector<int>().swap(int_vector);
	easyfind(int_vector,101);
	}catch(std::runtime_error &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		std::array<int, 5> int_array = {99, 0, -1, 1, 101};
		auto result4 = easyfind(int_array, 42);
		std::cout << result4 << std::endl;
	}catch(std::runtime_error &e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}