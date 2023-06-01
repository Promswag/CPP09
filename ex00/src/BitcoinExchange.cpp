#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <map>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
	std::string line, date, value;
	std::getline(file, line);
	while (file.good())
	{
		std::getline(file, line);
		date = line.substr(0, line.find_first_of(","));
		value = line.substr(line.find_first_of(","));
		if (!_date_is_valid(date) || !_value_is_valid(value))
		{
			std::cout << "Error while reading data, invalid format" << std::endl;
		}
		_entries.insert({date, std::stod(value)});
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &o)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &o)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::parse(std::ifstream &file) const
{
}
