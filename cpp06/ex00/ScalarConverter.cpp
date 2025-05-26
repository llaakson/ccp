#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	(void)copy;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &rhs){
	if (this != &rhs)
		return *this;
	return *this;
}
ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string convert)
{
	int c = stoi(convert);
	//std::string s = std::to_string(c);
	//char const *pchar = s.c_str(); 
	std::cout << "char: " << "'" << char(c) << "'" << std::endl;

	std::cout << "int: " << c << std::endl;

	std::cout << "float: " << std::stof(convert) << std::endl;

	std::cout << "double: " << std::stod(convert) << std::endl;
}