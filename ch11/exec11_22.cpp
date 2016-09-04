#include <iostream>
#include <map>
#include <string>
#include <vector>

int exec11_22_main()
{
    std::map<std::string, std::vector<int>> map;
    std::pair<std::map<std::string, std::vector<int>>::iterator, bool> pair = 
        map.insert(std::make_pair("aa",std::vector<int>(0)));
    return 0;
}