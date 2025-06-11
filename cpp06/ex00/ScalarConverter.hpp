#ifndef SCAlARCONVERTER_HPP
#define SCAlARCONVERTER_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <limits>

typedef enum {
	FLOAT,
	DOUBLE,
	CHAR,
	INT,
	SPECIAL,
} type_t;

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter();
	public :
		static void convert(std::string convert);
};

#endif