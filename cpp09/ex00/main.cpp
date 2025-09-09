#include "BitcoinExchange.hpp"

int main(int argc,char **argv)
{
	(void)argv;
	if (argc != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return -1;
	}
	try{
	BitcoinExchange ex;
	ex.Converter(argv);
	}
	catch (const std::invalid_argument& e) 
	{
        std::cout << "Invalid argument exception: " << e.what() << " !Exchange rate not valid" << std::endl;
    }
	catch (const std::out_of_range& e) 
	{
        std::cout << "Out of range exception: " << e.what() << " !Exchange rate not valid" << std::endl;
    }
	catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }


	return 0;
}