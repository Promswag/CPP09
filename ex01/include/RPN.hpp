#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN {
	std::string		_str;
	std::stack<double> _digits;
public:
	RPN();
	RPN(std::string &line);
	RPN(const RPN &o);
	RPN& operator=(const RPN &o);
	~RPN();

	void solution();
};

#endif