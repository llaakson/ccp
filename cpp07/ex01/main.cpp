#include "iter.hpp"

int main( void ) {
	int int_array[] = {4,56,3,224,424,1,0};
	std::string str_array[] = {"Banana", "Apple", "Carrot"};
	double double_array[] = {42.42, 42.41,0,0.2};

	::iter(int_array,7,ft_print_array);
	::iter(str_array,8,ft_print_array);
	::iter(double_array,4,ft_print_array);
	return 0;
}
 