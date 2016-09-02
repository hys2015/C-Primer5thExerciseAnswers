#include <string>
#include <map>
#include <iostream>


int exec11_03_main()
{
    std::string input;
    std::map<std::string, std::size_t> words;
    while (std::cin >> input) {
        words[input]++;
    }
    for (auto &w : words) {
        std::cout << w.first << ":" << w.second << std::endl;
    }
    return 0;
}