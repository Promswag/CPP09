#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Bad arguments -> ./btc path_to_file" << std::endl;
		return (0);
	}

	std::ifstream database;
	std::ifstream input;

	database.open("data.csv");
	input.open(argv[1]);
	if (!database.is_open() || !input.is_open())
	{
		std::cout << "Error loading file" << std::endl;
		return (0);
	}

	BitcoinExchange btc(database);

	std::string line;
	getline(input, line);
	while (input.good() && getline(input, line))
		btc.parse(line);
	return (0);
}