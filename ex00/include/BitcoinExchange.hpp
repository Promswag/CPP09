#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, double> _entries;
	bool _date_is_valid(std::string date);
	bool _date_is_valid(std::string value);
public:
	BitcoinExchange();
	BitcoinExchange(std::ifstream &file);
	BitcoinExchange(const BitcoinExchange &o);
	BitcoinExchange& operator=(const BitcoinExchange &o);
	~BitcoinExchange();

	void parse(std::ifstream &file) const;
};

#endif