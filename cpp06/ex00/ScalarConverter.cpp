#include "ScalarConverter.hpp"
#include <string>
#include <cstring>

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

int ScalarConverter::findType(std::string convert)
{
	size_t i = 0;
	int aa = 0;
	int bb = 0;
	if (convert.length() == 1 && (convert.find_first_not_of("0123456789") != std::string::npos))
		return (CHAR);
	if (convert[i] == '-' || convert[i] == '+')
		i++;
	if (convert.find_first_not_of("f.0123456789") != std::string::npos)
		return (SPECIAL);
	while (convert[i] != '\0')
	{
		if (convert[i] == '.')
			aa++;
		if (convert[i] == 'f')
			bb++;
		i++;
	}
	if (aa > 1 || bb > 1)
		return (SPECIAL);
	else if (convert.back() == 'f' && aa == 1)
		return (FLOAT);
	else if (convert.back() != 'f' && aa == 1)
		return (DOUBLE);
	else
		return (INT);
}

void ScalarConverter::convert(std::string convert)
{
	int type = findType(convert);
	std::cout << type << std::endl;

	if (type == FLOAT)
	{
		float c = std::stof(convert);
		std::cout << "char: " << "'" << char(c) << "'" << std::endl;
		std::cout << "int: " << int(c) << std::endl;
		std::cout << "float: " << convert << std::endl;
		std::cout << "double: " << c << std::endl;
	}
	else if (type == DOUBLE)
		std::cout << "conver DOUBLE" << std::endl;
	else if (type == CHAR)
		std::cout << "conver CHAR" << std::endl;
	else if (type == INT)
		std::cout << "conver INT" << std::endl;
	else if (type == SPECIAL)
		std::cout <<"conver SPECIAL" << std::endl;

	/*std::cout << "char: " << "'" << char(c) << "'" << std::endl;

	std::cout << "int: " << c << std::endl;

	std::cout << "float: " << std::stof(convert) << std::endl;

	std::cout << "double: " << std::stod(convert) << std::endl;*/
}