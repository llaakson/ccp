#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <iterator>
#include <map>
#include <iomanip> // for test print can be deleed
#include <string>
#include <algorithm>

class BitcoinExchange {
	private:
		std::map<std::string, float>_data_map;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &rhs);

		void Converter(char **argv);
		void print_conversion_rate(std::string date, float bitcoins, std::string one_line);
		void validate_date(std::string date);
		void validate_header(std::string date);
		bool validate_date_input(std::string &date);

};

#endif