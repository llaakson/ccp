#include "BitcoinExchange.hpp"

void read_record()
{
	fstream fin("data.csv");

	fin.open("reportcard.csv", ios::out | ios::app);

}

int main(int argc,char **argv)
{
	if (argc != 2){
		std::cerr << "Error: could not open file." << std::endl;
		return -1;
	}



	return 0;
}