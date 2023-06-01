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
	if (!database.good() || !input.good())
	{
		std::cout << "Error parsing file" << std::endl;
		return (0);
	}

	BitcoinExchange btc(database);
	btc.process(input);
	
	return (0);
}