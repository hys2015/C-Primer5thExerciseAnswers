#include <iostream>


int main()
{
	int caped = 10;
	auto f = [&caped]()->bool {
		if (caped) 
		{ 
			caped--; 
			return false; 
		} else 
			return true; 
	};
	std::cout << f() << std::endl;
	caped = 1;
	std::cout << f() << std::endl;
	std::cout << f() << std::endl;
	return 0;
}