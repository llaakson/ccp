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
	if (this != &rhs)
		return *this;;
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

	for (int i = 0; i < 10;i++){
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
	if (date.size() != 13 && date[11] != ' ' && date[12] != '|' && date[13] != ' ')
        return false;

    date = date.substr(0,10);

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10;i++){
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

void BitcoinExchange::print_conversion_rate(std::string date, double bitcoins)
{
    date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
    // double rate = 0;

    // for (auto it = _data_map.begin(); it != _data_map.end(); it++)
    // {
    //     //std::cout << it->first << " " << date << std::endl;
	// 	if (it->first == date){
    //         std::cout << "Found match" << std::endl;
    //         rate = it->second;
    //         break;
    //     }
    // }
    auto it = _data_map.lower_bound(date);

	std::cout << date << " => " << std::setprecision(9) << bitcoins << " = " << std::setprecision(9) << bitcoins * it->second << std::endl;
}

void BitcoinExchange::Converter(char **argv){
	std::fstream input;
    std::string one_line = "";
	std::string rate = "";
	std::string date = "";
    double int_rate = 0;

	input.open(argv[1]);
    if (!input.is_open())
    {
        throw std::runtime_error("Error! Could not open input.txt");
    }

    std::getline(input,date);
        if (date != "date | value")
            throw std::runtime_error("Error! Invalid Syntax: input header");

	while (std::getline(input, one_line)){
        date = one_line.substr(0,13);
	    bool validate_date = validate_date_input(date);
        if (!validate_date)
        {
            std::cerr << "Error bad input => " << one_line << std::endl; 
            continue;
        }
		rate = one_line.substr(13,std::string::npos);
        char c = rate[0];
        if (c == '-')
        {
            std::cerr << "Error: not a positive number" << std::endl; 
            continue;
        }
        if (rate.find_first_not_of("01234567898.") != std::string::npos)
        {
            std::cerr << "Error bad input => " << one_line << std::endl; 
            continue;
        }
        int_rate = std::stod(rate);
        if (int_rate > 1000)
        {
            std::cerr << "Error: too large number" << std::endl; 
            continue;   
        }
        print_conversion_rate(date,int_rate);
		

		//std::cout << "'" << date << " ' '" << int_rate << "'" << std::endl;
	}
}
