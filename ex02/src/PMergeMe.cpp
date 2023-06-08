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
			std::string str(values[j]);
			for (unsigned int i = 0; i < str.length(); i++)
				if (!isdigit(str[i]))
					throw "";
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
	if ((end - begin) > 4) {
		std::vector<unsigned int> a = sort_vector(begin, begin + (end - begin) / 2);
		std::vector<unsigned int> b = sort_vector(begin + (end - begin) / 2, end);
		std::vector<unsigned int>::iterator ita = a.begin();
		std::vector<unsigned int>::iterator itb = b.begin();
		while (ita != a.end() && itb != b.end()) {
			if (*ita < *itb)
				result.push_back(*ita++);
			else
				result.push_back(*itb++);
		}
		if (ita == a.end())
			while (itb != b.end())
				result.push_back(*itb++);
		if (itb == b.end())
			while (ita != a.end())
				result.push_back(*ita++);
	}
	else {
		for (std::vector<unsigned int>::iterator it = begin; it != end; it++) {
			std::vector<unsigned int>::iterator jt = result.begin();
			while (jt != result.end() && *jt < *it)
				jt++;
			result.insert(jt, *it);
		}
	}
	return result;
}

std::list<unsigned int> PmergeMe::sort_list(std::list<unsigned int>::iterator begin, std::list<unsigned int>::iterator end) {
	std::list<unsigned int> result;
	if (std::distance(begin, end) > 4) {
		std::list<unsigned int>::iterator mid = begin;
		std::advance(mid, std::distance(begin, end) / 2);
		std::list<unsigned int> a = sort_list(begin, mid);
		std::list<unsigned int> b = sort_list(mid, end);
		std::list<unsigned int>::iterator ita = a.begin();
		std::list<unsigned int>::iterator itb = b.begin();
		while (ita != a.end() && itb != b.end()) {
			if (*ita < *itb)
				result.push_back(*ita++);
			else
				result.push_back(*itb++);
		}
		if (ita == a.end())
			while (itb != b.end())
				result.push_back(*itb++);
		if (itb == b.end())
			while (ita != a.end())
				result.push_back(*ita++);
	}
	else {
		for (std::list<unsigned int>::iterator it = begin; it != end; it++) {
			std::list<unsigned int>::iterator jt = result.begin();
			while (jt != result.end() && *jt < *it)
				jt++;
			result.insert(jt, *it);
		}
	}
	return result;
}

void PmergeMe::pmergeme() {
	std::chrono::high_resolution_clock::time_point vstart = std::chrono::high_resolution_clock::now();
	std::vector<unsigned int> vec = sort_vector(_vector.begin(), _vector.end());
	std::chrono::high_resolution_clock::time_point vend = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point lstart = std::chrono::high_resolution_clock::now();
	std::list<unsigned int> lst = sort_list(_list.begin(), _list.end());
	std::chrono::high_resolution_clock::time_point lend = std::chrono::high_resolution_clock::now();
	std::cout << std::setw(10) << std::left << "Before: ";
	for (std::vector<unsigned int>::iterator it = _vector.begin(); it < _vector.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << std::setw(10) << std::left << "Vector: ";
	for (std::vector<unsigned int>::iterator it = vec.begin(); it < vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << std::setw(10) << std::left << "List: ";
	for (std::list<unsigned int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	std::cout << std::setw(36) << "Time to process using std::vector : ";
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(vend - vstart).count() << " us" << std::endl;
	std::cout << std::setw(36) << "Time to process using std::list : ";
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(lend - lstart).count() << " us" << std::endl;
}
