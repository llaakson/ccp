#include "ScalarConverter.hpp"
#include <iostream>

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error! Usage ./converter <argument>" << std::endl;
		return 1;
	}
	ScalarConverter Converter;
	Converter.convert(argv[1]);

	return 0;
}