#include "Array.hpp"
#include "Array.tpp"

int main(void){
	{
		Array<int> intArray{8};
		std::cout << intArray[0] << std::endl;
		std::cout << "Size of the string " << intArray.size() << std::endl;
		Array<int> intArray2(intArray);
		std::cout << intArray2[2] << std::endl;
		std::cout << "Size of the string " << intArray2.size() << std::endl;
	}
	// {
	// 	Array<char> charArray{8};
	// 	std::cout << charArray[0] << std::endl;
	// 	std::cout << "Size of the string " << charArray.size() << std::endl;
	// 	Array<char> charArray2(charArray);
	// 	std::cout << charArray2[2] << std::endl;
	// 	std::cout << "Size of the string " << charArray2.size() << std::endl;
	// }
	// {
	// 	try{
	// 		Array<int> intArray3{8};
	// 		std::cout << intArray3[42] << std::endl;
	// 		std::cout << "Size of the string " << intArray3.size() << std::endl;}
	// 	catch (std::runtime_error &e){
	// 		std::cerr << e.what() << std::endl;
	// 	}	
	// }
	return 0;
}