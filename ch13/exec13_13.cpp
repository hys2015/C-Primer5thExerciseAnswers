#include <iostream>
#include <vector>

struct X {
	X() 
	{
		std::cout << "X()" << std::endl;
	}
	X(const X&) 
	{
		std::cout << "X(const X&)" << std::endl;
	}
	X& operator=(const X&) 
	{
		std::cout << "operator=" << std::endl;
	}
	~X() 
	{
		std::cout << "destructor" << std::endl;
	}
};

void Foo1(const X&){} // no costruction , no destruction

void Foo2(const X){} // argument construction and its destruction

void Foo3()
{
	X *p = new X; // object p which point to is constructed
}

void Foo4()
{
	std::vector<X> vec;
	vec.push_back(X());
	// temperary X constructed and destructed
}

int exec13_13_main()
{
	X x;
	std::cout << "--------------" << std::endl;
	Foo1(x);
	std::cout << "--------------" << std::endl;
	Foo2(x);
	std::cout << "--------------" << std::endl;
	Foo3();
	std::cout << "--------------" << std::endl;
	Foo4();
	return 0;
}