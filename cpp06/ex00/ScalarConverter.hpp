#ifndef SCAlARCONVERTER_HPP
#define SCAlARCONVERTER_HPP
#include <iostream>
#include <string>

typedef enum {
	FLOAT,
	DOUBLE,
	CHAR,
	INT,
	SPECIAL,
} type_t;

class ScalarConverter {
	public :
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter();

		void convert(std::string convert);
		int findType(std::string convert);
};

#endif