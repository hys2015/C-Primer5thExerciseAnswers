#include <iostream>

int exec10_15_main()
{
    int rhs = 10;
    auto f = [rhs](int lhs){return lhs + rhs; };
    std::cout << f(4) << std::endl;
    return 0;
}