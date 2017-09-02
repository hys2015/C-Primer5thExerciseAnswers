#include <iostream>

class numbered {
public:
	numbered() {
		++mysn;
	}
	numbered(numbered &n) {
		mysn = n.mysn + 1;
	}
	static int mysn;
};

int numbered::mysn = 30;

void f(numbered &s) {
	std::cout << s.mysn << std::endl;
}

int exec13_17_3_main()
{
	numbered a, b = a, c = b;
	f(a);
	f(b);
	f(c);

	return 0;
}