#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool hasFiveOrMoreChars(const std::string &s)
{
    return s.size() < 5;
}

int exec10_13_main()
{
    std::vector<std::string> words;
    std::string input;
    while (std::cin >> input)
    {
        words.push_back(input);
    }
    auto iter = std::partition(words.begin(), words.end(), hasFiveOrMoreChars);
    while (iter != words.end())
    {
        std::cout << *iter << std::endl;
        iter++;
    }
    return 0;
}