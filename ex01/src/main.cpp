#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Bad arguments -> ./RPN \"operations\"" << std::endl;
		return (0);
	}

	std::string input(argv[1]);
	try {
		RPN rpn(input);
		rpn.solution();
	} catch (...) { return (1); }
	return (0);
}