#include <iostream>
#include <vector>
#include <map>
#include <string>

int main()
{
    std::map<std::string, std::vector<std::string>> families;
    std::string name;
    while (std::cout << "enter family's name: " && std::cin >> name) {
        auto &children = families[name];
        std::string cname;
        while (true) {
            std::cout << "enter children's name q to end:";
            std::cin >> cname;
            if ("q" == cname) break;
            children.push_back(cname);
        }
    }
    for (auto &f : families) {
        std::cout << f.first << ": " << std::endl;
        for (auto &c : f.second) {
            std::cout << "- " << c << std::endl;
        }
    }
    return 0;
}