#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <algorithm>

class PmergeMe {
	std::vector<unsigned int> _vector;
	std::list<unsigned int> _list;
	std::deque<unsigned int> _deque;
public:
	PmergeMe();
	PmergeMe(int i, char **values);
	PmergeMe(const PmergeMe &o);
	PmergeMe& operator=(const PmergeMe &o);
	~PmergeMe();

	void pmergeme();
	std::vector<unsigned int> sort_vector(
		std::vector<unsigned int>::iterator begin,
		std::vector<unsigned int>::iterator end);
	std::list<unsigned int> sort_list(
		std::list<unsigned int>::iterator begin,
		std::list<unsigned int>::iterator end);

	// template<class It, class T>
	// T sort(It b, It e)
	// {
	// 	T t;
	// 	if (e - b > 4) {
	// 		T l = sort(b, b + (e - b) / 2);
	// 		T r = sort(b + (e - b) / 2, e);
	// 		//merge
	// 	} else {
	// 		for (It it = b, it != e, it++) {
	// 			It jt = t.begin();
	// 			while (jt != t.end() && *jt < *it)
	// 				jt++;
	// 			t.insert(jt, *it);
	// 		}
	// 	}
	// 	return t;
	// }
};


#endif