#include "RPN.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <regex>

RPN::RPN() {}

RPN::RPN(std::string &line) {
	_str = line;
	std::string::iterator it = _str.begin();
	std::string c;
	while (it != _str.end()) {
		if (*it != ' ') {
			c = *it;
			if (!regex_match(c, std::regex("^[0-9]|[\\+-/\\*]$"))) {
				std::cout << "Error" << std::endl;
				throw std::invalid_argument("RPN::InvalidArgument");
			}
		}
		it++;
	}
}

RPN::RPN(const RPN &o) : _str(o._str), _digits(o._digits){}

RPN &RPN::operator=(const RPN &o) {
	if (this == &o)
		return *this;
	_str = o._str;
	_digits = o._digits;
	return *this;
}

RPN::~RPN() {}

void RPN::solution() {
	if (_str.length() == 0)
		return;
	std::string::iterator it = _str.begin();
	double a, b;
	while (it != _str.end()) {
		if (*it != ' ') {
			if (*it == '+' || *it == '-' || *it == '*' || *it == '/') {
				if (_digits.size() < 2) {
					std::cout << "Error" << std::endl;
					return;
				}
				b = _digits.top();
				_digits.pop();
				a = _digits.top();
				_digits.pop();
				if (*it == '/' && b == 0) {
					std::cout << "Error" << std::endl;
					return;
				}
				if (*it == '+')
					_digits.push(a + b);
				if (*it == '-')
					_digits.push(a - b);
				if (*it == '*')
					_digits.push(a * b);
				if (*it == '/')
					_digits.push(a / b);
			}
			else
				_digits.push(*it - '0');
		}
		it++;
	}
	if (_digits.size() != 1) {
		std::cout << "Error" << std::endl;
		return;
	}
	std::cout << _digits.top() << std::endl;
}
