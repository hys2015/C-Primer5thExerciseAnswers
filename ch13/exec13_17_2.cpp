#include <iostream>

#include "exec13_17_2.h"

//int numbered::mysn = 20;

static void f(numbered s) { std::cout << s.mysn << std::endl; }

int exec13_17_2_main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}