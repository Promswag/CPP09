#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, double> _entries;
	bool _date_is_valid(std::string date) const;
	bool _value_is_valid(std::string value) const;
public:
	BitcoinExchange();
	BitcoinExchange(std::ifstream &file);
	BitcoinExchange(const BitcoinExchange &o);
	BitcoinExchange& operator=(const BitcoinExchange &o);
	~BitcoinExchange();

	void parse(std::string &line) const;
};

#endif