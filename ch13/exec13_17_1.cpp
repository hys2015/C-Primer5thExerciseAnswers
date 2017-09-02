#include <iostream>

#include "exec13_17_1.h"

//int numbered::mysn = 10;

void f(numbered s) { std::cout << s.mysn << std::endl; }

int exec13_17_1_main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);
	return 0;
}