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

int ScalarConverter::findType(std::string convert)
{
	size_t i = 0;
	int isF = 0;
	int isDot = 0;
	if (convert.length() == 1 && (convert.find_first_not_of("0123456789") != std::string::npos))
		return (CHAR);
	if (convert == "nan" || convert == "+inf" || convert == "-inf")
		return (DOUBLE);
	if (convert == "nanf" || convert == "+inff" || convert == "-inff")
		return (FLOAT);
	if (convert.find_first_not_of("-+f.0123456789") != std::string::npos)
		return (SPECIAL);
	if (convert[i] == '-' || convert[i] == '+')
		i++;
	while (convert[i] != '\0')
	{
		if (convert[i] == '.')
			isDot++;
		if (convert[i] == 'f')
			isF++;
		if (convert[i] == '-' || convert[i] == '+')
			return (SPECIAL);
		i++;
	}
	if (isDot > 1 || isF > 1 || (isDot == 0 && isF == 1))
		return (SPECIAL);
	else if (convert.back() == 'f' && isDot == 1)
		return (FLOAT);
	else if (convert.back() != 'f' && isDot == 1 && isF == 0)
		return (DOUBLE);
	else if (convert.find_first_not_of("-+0123456789") != std::string::npos)
		return (SPECIAL);
	else
		return (INT);
}

void print_char(std::string convert)
{
	char c = convert[0];
	std::cout << "char: " << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void print_int(std::string convert){
	try {
	int i = stoi(convert);
	if (i >= 32 && i <= 126)
		std::cout << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;}
	catch (std::out_of_range &e){
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	}
}

void print_float(std::string convert){
		try {
		float f = std::stof(convert);
		if (f >= 32 && f <= 126)
			std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (std::isnan(f) || std::isinf(f))
			std::cout << "int: Non displayable" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << static_cast<float>(f)<< std::endl;}
		catch (std::out_of_range &e){
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		}
}

void print_double(std::string convert){
		try{
		double d = std::stod(convert);
		if (d >= 32 && d <= 126)
			std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (std::isnan(d) || std::isinf(d))
			std::cout << "int: Non displayable" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;}
		catch (std::out_of_range &e){
			std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
		}
}

void ScalarConverter::convert(std::string convert)
{	
	int type = findType(convert);
	std::cout << type << std::endl;
	switch (type){
		case FLOAT:
			print_float(convert);
			break;
		case DOUBLE:
			print_double(convert);
			break;
		case CHAR:
			print_char(convert);
			break;
		case INT:
			print_int(convert);
			break;
		case SPECIAL:
			std::cout << "Invalid input." << std::endl;}
}