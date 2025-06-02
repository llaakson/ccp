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

/*char convert_char(int i)
{
	if (i < 32 || i > 126)
		std::cout << "char : Non displayable" << std::endl;
	
}*/

void print_special(std::string convert)
{
	if (convert == "nan" || convert == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf"<< std::endl;
		std::cout << "double: nan" << convert << std::endl;
	}
	else if (convert == "+inf" || convert == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff"<< std::endl;
		std::cout << "double: +inf" << convert << std::endl;
	}
	else if (convert == "-inf" || convert == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff"<< std::endl;
		std::cout << "double: -inf" << convert << std::endl;
	}
	else
		std::cout << "Invalid input." << std::endl;
}

void ScalarConverter::convert(std::string convert)
{
	int type = findType(convert);
	std::cout << type << std::endl;

	if (type == FLOAT)
	{
		float f = std::stof(convert);
		std::cout << "char: " << "'" << char(f) << "'" << std::endl;
		std::cout << "int: " << int(f) << std::endl;
		std::cout << "float: " << convert << std::endl;
		std::cout << "double: " << f << std::endl;
	}
	else if (type == DOUBLE)
	{
		double d = std::stod(convert);
		std::cout << "char: " << "'" << char(d) << "'" << std::endl;
		std::cout << "int: " << int(d) << std::endl;
		std::cout << "float: " << convert << std::endl;
		std::cout << "double: " << convert << std::endl;
	}
	else if (type == CHAR)
	{
		char c = std::stof(convert); //aergaerg
		std::cout << "char: " << "'" << c << "'" << std::endl;
		std::cout << "int: " << int(c) << std::endl;
		std::cout << "float: " << float(c) << std::endl;
		std::cout << "double: " << double(c) << std::endl;
	}
	else if (type == INT)
	{
		int i = stoi(convert);
		std::cout << "char: " << "'" << char(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << double(i) << std::endl;
		std::cout << "double: " << double(i) << std::endl;
	}
	else if (type == SPECIAL)
		print_special(convert);

}