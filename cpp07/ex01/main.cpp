#include "iter.hpp"

int main( void ) {
	int int_array[] = {4,56,3,224,424,1,0};
	std::string str_array[] = {"Banana", "Apple", "Carrot"};
	double double_array[] = {42.42, 42.41,0,0.2};

	iter(int_array,7,ft_print_array<int>);
	iter(str_array,3,ft_print_array<std::string>);
	iter(double_array,4,ft_print_array<double>);

	iter(double_array,4,ft_print_array2);
	iter(int_array,7,ft_print_array2);
	iter(str_array,3,ft_print_array2);

	return 0;
}
 