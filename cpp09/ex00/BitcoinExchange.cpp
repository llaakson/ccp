#include "BitcoinExchange.hpp"

#include <iterator>

BitcoinExchange::BitcoinExchange() : _amount(0) {
	std::fstream data;
	std::string date = "";
	std::string rate = "";
	data.open("data.csv");
	while (std::getline(data,date)){
		std::getline(data, date, ',');
		std::getline(data, rate);
		_data_map.insert({date,std::stod(rate)});
	}
	//  for (auto it = _data_map.begin(); it != _data_map.end(); it++){
	//  	std::cout << "'" << it->first << " ' '" << it->second << "'" << std::endl;
	//  }

}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs){
	if (this != &rhs)
		return *this;;
	return *this;
	
}

void BitcoinExchange::Print_conversion_rate(std::string date, double rate){
	if (_amount > 1000){
		std::cout << "Error: too large a number."<< std::endl;
	}
	else
		std::cout << date << " => " << _amount << " = " << _amount * rate << std::endl;
}

void BitcoinExchange::amount_value_check(std::string n, std::string date){
	try{
		n.erase(n.find_last_not_of(" "));
		std::string::const_iterator it = n.begin();
   		while (it != n.end()){
			if (*it == '-'){
				std::cout << "Error: not positive number."<< std::endl;
				_amount = -1;
				return ;
			}
			else if (!(std::isdigit(*it))){
				std::cout << "Error: bad input => : " << *it << " " << date << std::endl;
				_amount = -1;
				return ;
			}
			++it;
		}
		_amount = std::stoi(n);
	}
	catch(std::invalid_argument){
		std::cout << "Error: bad input => " << date << std::endl;
	}
	catch(std::out_of_range){
		std::cout << "Error: too large a number."<< std::endl;
	}
}

void BitcoinExchange::Converter(char **argv){
	std::fstream input;
	std::string rate = "";
	std::string date = "";
	input.open(argv[1]);

	while (std::getline(input,date)){
		std::getline(input, date, '|');
		std::getline(input, rate);
			// amount_value_check(rate,date);
			// continue ;}
		amount_value_check(rate,date);
		// if (_amount == -1)
		//  	continue ;
		date.erase(date.find_last_not_of(" ") + 1);
		for (auto it = _data_map.begin(); it != _data_map.end(); it++){
			if (it->first == date){
				//std::cout << "Found match" << std::endl;
				Print_conversion_rate(date,it->second);
			}
		}
		//std::cout << "'" << date << " ' '" << rate << "'" << std::endl;
	}
}

