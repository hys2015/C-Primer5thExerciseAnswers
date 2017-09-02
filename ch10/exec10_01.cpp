#include <algorithm>

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec;
    int in;
    std::cout << "set your vector of ints(-1 means ending): ";
    while (std::cin >> in)
    {
        if (in == -1) break;
        vec.push_back(in);
    }
    std::cout << "enter your int: ";
    std::cin >> in;
    std::cout << in << " count is "
              << count(vec.cbegin(), vec.cend(), in) << std::endl;

    return 0;
}