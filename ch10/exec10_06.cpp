#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int exec10_06_main()
{
    std::vector<int> vec;
    std::fill_n(std::back_inserter(vec), 10, 3);

    return 0;
}