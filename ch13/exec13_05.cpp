#include <iostream>
#include "exec13_05.h"

HasPtr::HasPtr(const HasPtr &rhs):
	i(rhs.i)
{
	this->ps = new std::string(*rhs.ps);
}

int exec13_05_main()
{
	HasPtr p1("copy me!");
	HasPtr p2(p1);
	return 0;
}