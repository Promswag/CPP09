#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <iterator>

PmergeMe::~PmergeMe() {}


PmergeMe::PmergeMe(int i, char **values) {
	for (int j = 0; j < i; j++) {
		if (std::stoi(values[j]) < 0)
			throw "";
		_vector.push_back(std::stoi(values[j]));
		_list.push_back(std::stoi(values[j]));
	}
}

PmergeMe::PmergeMe(const PmergeMe & o) : _vector(o._vector), _list(o._list) {}

PmergeMe & PmergeMe::operator=(const PmergeMe & o) {
	if (this == &o)
		return *this;
	_vector = o._vector;
	_list = o._list;
	return *this;
}

PmergeMe::PmergeMe() {}

std::vector<unsigned int> PmergeMe::sort_vector(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end) {
	if ((end - begin) > 1) {
		std::vector<unsigned int> one sort_vector(begin, begin + (end - begin) / 2);
		std::vector<unsigned int> two sort_vector(begin + (end - begin) / 2, end);
		std::merge()
	}
	else {

	}
	return std::vector<unsigned int>();
}

std::list<unsigned int> PmergeMe::sort_list(std::list<unsigned int>::iterator begin, std::list<unsigned int>::iterator end) {
	return std::list<unsigned int>();
}
