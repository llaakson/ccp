#include "Array.hpp"
#include "Array.tpp"

int main(void){

	Array<int> intArray{4};
	std::cout << intArray[0] << std::endl;
	std::cout << "Size of the string " << intArray.size() << std::endl;
	return 0;
}