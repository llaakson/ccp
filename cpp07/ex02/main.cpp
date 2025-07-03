#include <iostream>
#include "Array.hpp"

int main(void)
{
	std::cout << "--test 1--" << std::endl;
	try
	{
		Array<int> numbers(10);
		for (size_t i = 0; i < 10; i++)
		{
			//std::cout << "number from array: " << numbers[i] << std::endl;
			numbers[i] = i;
		}
		std::cout << std::endl;
		for (size_t j = 0; j < 10; j++)
			std::cout << "number from array: " << numbers[j] << std::endl;
		std::cout << std::endl;
		Array<int> copy(numbers);
		for (size_t i = 0; i < 10; i++)
			std::cout << "number from copy array: " << copy[i] << std::endl;
		std::cout << numbers.size() << ": numbers size\n";
		std::cout << copy.size() << ": copy size\n";

		std::cout << "At index 9: " << numbers[9] << std::endl;
		std::cout << "At index 0: " << numbers[0] << std::endl;
		//std::cout << "At index 11: " << numbers[11] << std::endl;
		std::cout << "At index -2: " << numbers[-2] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "something else went wrong...";
	}
	std::cout << std::endl << "--test 2 (with a new)--" << std::endl;
	{
		Array<int>* intArray = nullptr;
		try{
			intArray = new Array<int>(5);
			for (size_t i = 0; i < intArray->size(); i++)
				(*intArray)[i] = i * 10;
			for (size_t i = 0; i < intArray->size(); i++)
				std::cout << (*intArray)[i] << std::endl;
			std::cout << "testing size(): " << intArray->size() << std::endl;
			std::cout << "testing out of bounds: " << (*intArray)[10] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...)
		{
			std::cout << "something else went wrong...";
		}
		delete intArray;
	}
	std::cout << std::endl <<  "--test 3 (with assignement operator)--" << std::endl;
	try
	{
		Array<std::string> original(3);
		original[0] = "i";
		original[1] = "love";
		original[2] = "dogs";

		std::cout << "Original array of strings: " << std::endl;
		for (size_t i = 0; i < original.size(); i++)
			std::cout << original[i] << " ";
		
		Array<std::string> assigned;
		assigned = original;
		std::cout << std::endl << "checking assignement...: " << std::endl;
		for (size_t i = 0; i < assigned.size(); i++)
			std::cout << assigned[i] << " ";
		original[2] = "ALL ANIMALS";
		assigned[2] = "CATS";
		std::cout << std::endl << "does changing one array affect the other...?" << std::endl;
		std::cout << std::endl << "Original array of strings: " << std::endl;
		for (size_t i = 0; i < original.size(); i++)
			std::cout << original[i] << " ";
		std::cout << std::endl << "Assigned array...: " << std::endl;
		for (size_t i = 0; i < assigned.size(); i++)
			std::cout << assigned[i] << " ";
		std::cout << std::endl;
		//original[3] = "!!!!!!";
		//throw 42;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "stop breaking my code, Leo!!!" << std::endl;
	}
	std::cout << std::endl << "--test 4--" << std::endl;
	// try
	// {
	// 	Array<int> intArray(0);
	// 	std::cout << "size of array: " << intArray.size() << std::endl;
	// 	Array<int> intArray2(-2);
	// 	std::cout << "size of array: " << intArray2.size() << std::endl;
	// }
	// catch (const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }
	// catch (...)
	// {
	// 	std::cout << "something else went wrong..." << std::endl;
	// }
	// 	std::cout << std::endl << "--test 5 (const subscript operator with bounds check)--" << std::endl;
	try
	{
		Array<int> arr(5);
		for (size_t i = 0; i < arr.size(); i++)
			arr[i] = i * 3;
		const Array<int>& constArr = arr; 
		std::cout << "Accessing elements through const reference:\n";
		for (size_t i = 0; i < constArr.size(); i++)
			std::cout << constArr[i] << " ";
		std::cout << std::endl;
		constArr[0] = 100; //- won't compile because [] returns const

		std::cout << "Trying to access out-of-bounds index...\n";
		std::cout << constArr[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unexpected exception caught.\n";
	}
	return 0;
}
