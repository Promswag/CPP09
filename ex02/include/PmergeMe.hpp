#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe {
	std::vector<unsigned int> _vector;
	std::list<unsigned int> _list;
public:
	PmergeMe();
	PmergeMe(int i, char **values);
	PmergeMe(const PmergeMe &o);
	PmergeMe& operator=(const PmergeMe &o);
	~PmergeMe();

	std::vector<unsigned int> sort_vector(
		std::vector<unsigned int>::iterator begin,
		std::vector<unsigned int>::iterator end);
	std::list<unsigned int> sort_list(
		std::list<unsigned int>::iterator begin,
		std::list<unsigned int>::iterator end);
};

#endif