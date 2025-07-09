#include "iter.hpp"

int main( void ) {
	std::cout << "Int array" << std::endl;
	int int_array[] = {4,56,3,224,424,1,0}; 
	std::string str_array[] = {"Banana", "Apple", "Carrot"};
	double double_array[] = {42.42, 42.41,0,0.2};

	std::cout << "Int array" << std::endl;
	iter(int_array,std::size(int_array),ft_print_array<int>);
	std::cout << "String array" << std::endl;
	iter(str_array,std::size(str_array),ft_print_array<std::string>);
	std::cout << "Double array" << std::endl;
	iter(double_array,std::size(double_array),ft_print_array<double>);

	std::cout << "\nTesting non const\n" << std::endl;

	std::cout << "Int array" << std::endl;
	iter(int_array,std::size(int_array),ft_print_array2);
	std::cout << "String array" << std::endl;
	iter(str_array,std::size(str_array),ft_print_array2);
	std::cout << "Double array" << std::endl;
	iter(double_array,std::size(double_array),ft_print_array2);

	return 0;
}