#include "PmergeMe.hpp"
#include <iostream>
#include <set>

int main(int argc, char **argv)
{
	// std::vector<int> v;
	// v.push_back(0);
	// v.push_back(5);
	// v.push_back(2);
	// v.push_back(3);
	// v.push_back(9);

	// std::list<int> l;
	// l.push_back(5);
	// l.push_back(0);
	// l.push_back(2);
	// l.push_back(3);
	// l.push_back(9);

	// std::set<int> s;
	// s.insert(5);
	// s.insert(0);
	// s.insert(2);
	// s.insert(3);
	// s.insert(9);

	// std::vector<int>::iterator begin = v.begin();
	// std::vector<int>::iterator end = v.end();
	// std::list<int>::iterator lbegin = l.begin();
	// std::list<int>::iterator lend = l.end();
	// std::set<int>::iterator sbegin = s.begin();
	// std::set<int>::iterator send = s.end();
	// std::cout << end - begin << std::endl;
	// // std::cout << lend - lbegin << std::endl;
	// std::cout << send - sbegin << std::endl;
	// std::cout << std::distance(begin, end) << std::endl;
	// std::cout << std::distance(lbegin, lend) << std::endl;
	// std::cout << std::distance(sbegin, send) << std::endl;
	if (argc < 2)
	{
		std::cout << "Bad arguments -> ./PmergeMe list_of_positive_integers" << std::endl;
		return (0);
	}
	try {
		PmergeMe me(argc - 1, argv + 1);
		me.pmergeme();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	
	return (0);
}