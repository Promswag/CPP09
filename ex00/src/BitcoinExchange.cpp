#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>
#include <regex>
#include <map>

bool BitcoinExchange::_date_is_valid(std::string date) const
{
	struct tm tm;
	if (!strptime(date.c_str(), "%Y-%m-%d", &tm) || tm.tm_mday == 0)
		return false;
	return true;
}

bool BitcoinExchange::_value_is_valid(std::string value) const
{
	return regex_match(value, std::regex("^\\d+(\\.\\d+)?$"));
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
	std::string line, date, value;
	std::getline(file, line);
	while (file.good() && std::getline(file, line))
	{
		date = line.substr(0, line.find_first_of(","));
		value = line.substr(line.find_first_of(",") + 1);
		if (!_date_is_valid(date) || !_value_is_valid(value))
			std::cout << "Error while reading data, invalid format" << std::endl;
		else
			_entries[date] = std::stod(value);
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

void BitcoinExchange::parse(std::string &line) const
{
	std::string date, value;
	try {
		date = line.substr(0, line.find_first_of("|"));
		value = line.substr(line.find_first_of("|") + 2);
	} catch (std::exception &e) {}

	if (!_date_is_valid(date))
		std::cout << "Error: bad input => " << line << std::endl;
	else
	{
		double val;
		try {val = std::stod(value);} catch(std::exception &e) {}
		if (val < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (val > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else if (!_value_is_valid(value))
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			std::map<std::string, double>::const_iterator it = _entries.upper_bound(date);
			it--;
			std::cout << line << " => " << val *  it->second << std::endl;
		}
	}
}
