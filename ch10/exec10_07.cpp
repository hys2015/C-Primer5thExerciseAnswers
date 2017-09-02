#include <iostream>

#include <vector>
#include <algorithm>
#include <iterator>

int a_main()
{
    std::vector<int> vec({ 1, 2, 3, 4, 5, 6 });
    std::vector<int> vec2;
    std::copy(vec.begin(), vec.end(), std::back_inserter(vec2));
    return 0;
}

int b_main()
{
    std::vector<int> vec;
    vec.reserve(10);
    std::fill_n(std::back_inserter(vec), 10, 3);
    return 0;
}

int main()
{
    //a_main();
    b_main();
    return 0;
}