#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std::placeholders;

bool check_size(const std::size_t sz, const std::string &spec)
{
    return sz > spec.size();
}

int exec10_24_main()
{
    std::cout << "your specific string: " << std::endl;
    std::string spec;
    std::cin >> spec;
    std::vector<int> nums;
    std::cout << "enter the nums ^Z to end:";
    int num;
    while (std::cin >> num)
    {
        nums.push_back(num);
    }
    auto ite = std::find_if(nums.begin(), nums.end(), bind(check_size, _1, spec));
    std::cout << *ite << std::endl;
    return 0;
}