#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <ctype.h>

void tolower_str(std::string &s)
{
    for (auto &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
    }
}

bool isLetter(const char c) {
    return c >= 'a' && c <= 'z';
}

int exec11_04_main()
{
    std::string input;
    std::map<std::string, std::size_t> words;
    while (std::cin >> input) {
        tolower_str(input);
        auto ite = std::stable_partition(input.begin(), input.end(), isLetter);
        input.erase(ite, input.end());
        words[input]++;
    }
    for (auto &w : words) {
        std::cout << w.first << ":" << w.second << std::endl;
    }
    return 0;
}