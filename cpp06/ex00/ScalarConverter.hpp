#ifndef SCAlARCONVERTER_HPP
#define SCAlARCONVERTER_HPP
#include <iostream>

class ScalarConverter {
	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter();

		void convert(std::string convert);
};

#endif