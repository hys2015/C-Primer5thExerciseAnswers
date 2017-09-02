#include <algorithm>
#include <string>
#include <list>

#include <iostream>

int main()
{
    std::list<std::string> list;
    std::string in;
    std::cout << "set your vector of strings(q means ending): ";
    while (std::cin >> in)
    {
        if (in == "q") break;
        list.push_back(in);
    }
    std::cout << "enter your string: ";
    std::cin >> in;
    std::cout << in << " count is "
        << count(list.cbegin(), list.cend(), in) << std::endl;

    return 0;
}