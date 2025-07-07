#include <iostream>
#include "Array.hpp"

int main (void){
	std::cout << "----FiRST TEST-------" << std::endl;
	try{
		Array<int> empty_array{};
		empty_array[-1];
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;}
	catch(...){
		std::cerr << "Something went error" << std::endl;}

	std::cout << "----Second TEST-------" << std::endl;

	try{
		Array<int> five_array(5);
		for (size_t i = 0; i < five_array.size(); i++)
			five_array[i] = i * i;
		std::cout << five_array[3] << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;}
	catch(...){
		std::cerr << "Something went error" << std::endl;}

	std::cout << "----Thrid TEST-------" << std::endl;

	try{
		Array<char> char_arr(5);
		for (size_t i = 0; i < char_arr.size(); i++)
			char_arr[i] = 'a';
		std::cout << char_arr[2] << std::endl;

		const Array<char>& constArr = char_arr;
		std::cout << constArr[2] << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;}
	catch(...){
		std::cerr << "Something went error" << std::endl;}

	std::cout << "----Copy testing empty arrays----" << std::endl;
	try{
		Array<int> empty_array{};
		Array<int> empty_array_second(empty_array);
		empty_array = empty_array_second;
		std::cout << "Size is " << empty_array.size() << std::endl;
		std::cout << "Size is " << empty_array_second.size() << std::endl;
		std::cout << "Nothing to see here, just be happy that it does not segfault" << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;}
	catch(...){
		std::cerr << "Something went error" << std::endl;}

	std::cout << "----Copy testing real arrays----" << std::endl;
	try{
		Array<int> int_array(5);
		for (size_t i = 0; i < int_array.size(); i++)
			int_array[i] = i;
		Array<int> int_array_second(int_array);
		std::cout << int_array[2] << std::endl;
		std::cout << int_array_second[2] << std::endl;
		for (size_t i = 0; i < int_array_second.size(); i++)
			int_array_second[i] += 1;
		int_array = int_array_second;
		std::cout << int_array[2] << std::endl;
		std::cout << int_array_second[2] << std::endl;
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;}
	catch(...){
		std::cerr << "Something went error" << std::endl;}
	return 0;
}