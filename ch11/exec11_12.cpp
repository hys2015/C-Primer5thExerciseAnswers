#include <iostream>
#include <vector>
#include <utility>
#include <string>

int exec11_12_main()
{
    std::vector<std::pair<std::string, int> > vec;
    std::string i_str;
    int i_int;
    while (std::cin >> i_str && std::cin >> i_int)
    {
        std::pair<std::string, int> pair(i_str, i_int);
        vec.push_back(pair);
    }
    for (auto &c : vec)
    {
        std::cout << c.first << " - " << c.second << std::endl;
    }

    return 0;
}