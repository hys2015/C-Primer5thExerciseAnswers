#include <map>
#include <iostream>
#include <string>

int exec11_16_main()
{
    std::string value("7");
    std::map<int, std::string> map;
    map[0] = "aa";
    auto map_it = map.begin();
    map_it->second = value;
    
    return 0;
}