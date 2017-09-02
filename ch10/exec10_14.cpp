#include <iostream>

int main()
{
    auto sum = [](int a, int b){return (a + b); };
    std::cout << sum(1, 3) << std::endl;
    std::cout << sum(0, 4) << std::endl;
    std::cout << sum(9, -10) << std::endl;
    return 0;
}