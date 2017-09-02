#pragma once
#include <string>
#include <iostream>
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()):
		ps(new std::string(s)), i(0)
	{}
	HasPtr(const HasPtr &rhs):
		ps(new std::string(*rhs.ps)),
		i(rhs.i)
	{}
	~HasPtr() {
		delete ps;
		std::cout << "destructor" << std::endl;
	}
private:
	std::string *ps;
	int i;
};