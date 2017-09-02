#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<const char* > roster1({ "abc", "xyz" });
    std::vector<const char* > roster2({ "abc", "xyz" });

    std::cout << std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << std::endl;

    std::cout << ("abc" == "abc");
    std::cout << ("abc" == "xxx") << std::endl;

    return 0;
}