#include <string>
#include <map>
#include <iostream>


int exec11_20_main()
{
    std::map<std::string, std::size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        std::pair<std::map<std::string, std::size_t>::iterator, bool>
            pr = word_count.insert(std::make_pair(word, 1));
        if (!pr.second)
        {
            ++(pr.first)->second;
        }
    }
    for (auto &c : word_count)
    {
        std::cout << c.first << " occurs "
            << c.second << (c.second > 1 ? " times" : " time") << std::endl;
    }
    return 0;
}