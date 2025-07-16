#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double>_data_map;
		int _amount;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &rhs);

		void Converter(char **argv);
		void Print_conversion_rate(std::string date, double rate);
		void amount_value_check(std::string n, std::string date);

};

#endif