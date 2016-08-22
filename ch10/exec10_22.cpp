#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

bool isShorter6(const std::string &str)
{
    return str.size() <= 6;
}

int exec10_22_main()
{
    std::vector<std::string> words;
    std::cout << "enter the words ^Z to end:";
    std::string input;
    while (std::cin >> input)
    {
        words.push_back(input);
    }
    std::cout << std::count_if(words.begin(), words.end(),isShorter6) << std::endl;

    return 0;
}