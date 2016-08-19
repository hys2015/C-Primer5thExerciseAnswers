#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

int exec10_03_main()
{
    std::vector<int> vec({ 1, 2, 3, 4, 5, 6 });
    std::cout << std::accumulate(vec.cbegin(), vec.cend(), 0) << std::endl;

    return 0;
}