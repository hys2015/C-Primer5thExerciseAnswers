#include <iostream>
#include "exec13_08.h"


int exec13_08_main()
{
	HasPtr hp1("copy-assignment");
	HasPtr hp2;
	hp2 = hp1;
	
	return 0;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	this->ps = new std::string(*rhs.ps);
	this->i = rhs.i;
	return *this;
}

