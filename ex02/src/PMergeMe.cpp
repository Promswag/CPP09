#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <chrono>
#include <stdexcept>
	
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(int i, char **values) {
	for (int j = 0; j < i; j++) {
		try {
			if (std::stoi(values[j]) < 0)
				throw "";
		} catch (...) {
			throw std::invalid_argument(std::string("Invalid input -> ") + values[j]);
		}
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
	std::vector<unsigned int> result;
	if ((end - begin) > 1) {
		std::vector<unsigned int> a = sort_vector(begin, begin + (end - begin) / 2);
		std::vector<unsigned int> b = sort_vector(begin + (end - begin) / 2, end);
		std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
	}
	else
		result.push_back(*begin);
	return result;
}

std::list<unsigned int> PmergeMe::sort_list(std::list<unsigned int>::iterator begin, std::list<unsigned int>::iterator end) {
	std::list<unsigned int> result;
	if (std::distance(begin, end) > 1) {
		std::list<unsigned int>::iterator mid = begin;
		std::advance(mid, std::distance(begin, end) / 2);
		std::list<unsigned int> a = sort_list(begin, mid);
		std::list<unsigned int> b = sort_list(mid, end);
		a.merge(b);
		return a;
	}
	else {
		result.push_back(*begin);
		return result;
	}
}

void PmergeMe::pmergeme() {
	std::vector<unsigned int> vec;
	std::list<unsigned int> lst;
	std::chrono::high_resolution_clock::time_point vstart = std::chrono::high_resolution_clock::now();
	vec = sort_vector(_vector.begin(), _vector.end());
	std::chrono::high_resolution_clock::time_point vend = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point lstart = std::chrono::high_resolution_clock::now();
	lst = sort_list(_list.begin(), _list.end());
	std::chrono::high_resolution_clock::time_point lend = std::chrono::high_resolution_clock::now();
	std::cout << std::setw(10) << std::left << "Before: ";
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it < _vector.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << std::setw(10) << std::left << "After: ";
	for (std::vector<unsigned int>::iterator it = vec.begin(); it < vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << std::setw(36) << "Time to process using std::vector : ";
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(vend - vstart).count() << " us" << std::endl;
	std::cout << std::setw(36) << "Time to process using std::list : ";
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(lend - lstart).count() << " us" << std::endl;

}
