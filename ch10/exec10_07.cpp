#include <iostream>

#include <vector>
#include <algorithm>
#include <iterator>

int exec10_07_a_main()
{
    std::vector<int> vec({ 1, 2, 3, 4, 5, 6 });
    std::vector<int> vec2;
    std::copy(vec.begin(), vec.end(), std::back_inserter(vec2));
    return 0;
}

int exec10_07_b_main()
{
    std::vector<int> vec;
    vec.reserve(10);
    std::fill_n(std::back_inserter(vec), 10, 3);
    return 0;
}