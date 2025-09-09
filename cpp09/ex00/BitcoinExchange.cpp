#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{
	std::fstream data;
	std::string date = "";
	std::string rate = "";

	data.open("data.csv");
    if (!data.is_open())
    {
        throw std::runtime_error("Error! Could not open data.csv");
    }

    std::getline(data,date);
        validate_header(date);

	while (std::getline(data, date, ','))
    {
		std::getline(data, rate);
        validate_date(date);
		_data_map.insert({date,std::stod(rate)});
	}
	// for (auto it = _data_map.begin(); it != _data_map.end(); it++)
    // {
	//     std::cout << "'" << it->first << " ' '" << std::setprecision(9) << it->second << "'" << std::endl;
	// }
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs){
	if (this != &rhs){
		_data_map = rhs._data_map;
	}
	return *this;
	
}

void BitcoinExchange::validate_header(std::string date)
{
    if (date != "date,exchange_rate")
        throw std::runtime_error("Error! Invalid Syntax: header");
}

void BitcoinExchange::validate_date(std::string date){
	//std::cout  << date << std::endl;
	if (date.size() != 10)
        throw std::runtime_error("Error! Invalid Syntax: date");

	if (date[4] != '-' || date[7] != '-')
		throw std::runtime_error("Error! Invalid Syntax: date");

	for (int i = 0; i < 10 ; i++){
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			throw std::runtime_error("Error! Invalid Syntax: date");
	}
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year = std::stoi(date.substr(0,4));
	int month = std::stoi(date.substr(5,2));
	int day = std::stoi(date.substr(8,2));

	if (year < 2009)
		throw std::runtime_error("Error! Invalid Syntax: year");
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
		days[1] = 29;
	if (month < 1 || month > 12)
		throw std::runtime_error("Error! Invalid Syntax: month");
	if (day < 1 || day > days[month - 1])
		throw std::runtime_error("Error! Invalid Syntax: day");
}


bool BitcoinExchange::validate_date_input(std::string &date)
{
    //std::cout  <<"|" << date << "|" << std::endl;
	if (date.size() != 13 || date[10] != ' ' || date[11] != '|' || date[12] != ' ')
        return false;

    date = date.substr(0,10);

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year = std::stoi(date.substr(0,4));
	int month = std::stoi(date.substr(5,2));
	int day = std::stoi(date.substr(8,2));

	if (year < 2009)
		return false;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
		days[1] = 29;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > days[month - 1])
		return false;
    return true;
}

void BitcoinExchange::print_conversion_rate(std::string date, float bitcoins, std::string one_line)
{
    date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
    auto it = _data_map.lower_bound(date);
	if (it == _data_map.end() || date != it->first)
	{
		if (it == _data_map.begin())
		{
			std::cerr << "Error: bad input => " << one_line << std::endl;
			return ;
		}
		else
			it--;
	}
	//std::cout  << "rate is: " << it->second << "date is: " << it->first << std::endl;; 
	std::cout << date << " => " << std::setprecision(2) << bitcoins << " = " << std::setprecision(2) << bitcoins * it->second << std::endl;
}

void BitcoinExchange::Converter(char **argv){
	std::fstream input;
    std::string one_line = "";
	std::string rate = "";
	std::string date = "";
    float int_rate = 0;

	input.open(argv[1]);
    if (!input.is_open())
    {
        throw std::runtime_error("Error: Could not open file");
    }

    std::getline(input,date);
        if (date != "date | value")
            throw std::runtime_error("Error! Invalid Syntax: input header");

	while (std::getline(input, one_line)){
        date = one_line.substr(0,13);
	    bool validate_date = validate_date_input(date);
        if (!validate_date)
        {
            std::cerr << "Error: bad input => " << one_line << std::endl; 
            continue;
        }
		rate = one_line.substr(13,std::string::npos);
        char c = rate[0];
        if (c == '-')
        {
            std::cerr << "Error: not a positive number" << std::endl; 
            continue;
        }
        if (rate.find_first_not_of("0123456789.") != std::string::npos)
        {
            std::cerr << "Error: bad input => " << one_line << std::endl; 
            continue;
        }
		auto count = std::ranges::count(one_line, '.');
		if (count > 1)
		{
			std::cerr << "Error: bad input => " << one_line << std::endl; 
            continue;
		}
		try{
        	int_rate = std::stod(rate);
		}
		catch (...){
			std::cerr << "Error: bad input => " << one_line << std::endl;
		}
        if (int_rate > 1000)
        {
            std::cerr << "Error: too large number" << std::endl; 
            continue;   
        }
        print_conversion_rate(date,int_rate,one_line);
		//std::cout << "'" << date << " ' '" << int_rate << "'" << std::endl;
	}
}
