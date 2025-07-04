#include "iter.hpp"

int main( void ) {
	int int_array[] = {4,56,3,224,424,1,0};
	std::string str_array[] = {"Banana", "Apple", "Carrot"};
	double double_array[] = {42.42, 42.41,0,0.2};

	iter(int_array,7,ft_print_array);
	iter(str_array,3,ft_print_array);
	iter(double_array,4,ft_print_array);
	return 0;
}

// class Awesome
// {
// 	public:
// 	Awesome( void ) : _n( 42 ) { return; }
// 	int get( void ) const { return this->_n; }
// 	private:
// 	int _n;
// 	};
// 	std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; 
// }

// template< typename T >
// void ft_print( T const & x ) { std::cout << x << std::endl; return; }

// int main() {
// 	int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
// 	Awesome tab2[5];
// 	iter( tab, 5, ft_print );
// 	iter( tab2, 5, ft_print );
// 	return 0;
// }
 