#include <vector>
#include <map>
#include <string>
#include <iostream>

int exec11_28_main()
{
    std::map<std::string, std::vector<int>> map;
    map.insert(std::make_pair<std::string, std::vector<int>>("aa", std::vector<int>({ 0, 1 })));
    std::map<std::string, std::vector<int>>::iterator it = map.find("aa");
    for (auto &c : it->second)
    {
        std::cout << c << std::endl;
    }
    return 0;
}