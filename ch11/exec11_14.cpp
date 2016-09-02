#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

int exec11_14_main()
{
    std::map<std::string, std::vector<std::pair<std::string, std::string>>> families;
    std::string name;
    while (std::cout << "enter family's name: " && std::cin >> name) {
        auto &children = families[name];
        std::string cname;
        std::string birthday;
        while (true) {
            std::cout << "enter children's name q to end:";
            std::cin >> cname;
            if ("q" == cname) break;
            std::cout << "enter children's birthday: (yyyymmdd)";
            std::cin >> birthday;
            if ("q" == birthday) break;
            children.push_back(std::make_pair(cname, birthday));
        }
    }
    for (auto &f : families) {
        std::cout << f.first << ": " << std::endl;
        for (auto &c : f.second) {
            std::cout << "- " << c.first << "birthday: "<< c.second << std::endl;
        }
    }
    return 0;
}