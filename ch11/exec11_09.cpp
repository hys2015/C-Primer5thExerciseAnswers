#include <map>
#include <list>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::map<std::string, std::list<std::size_t>> word_linenum;
    std::string line;
    std::size_t linenum = 1;
    while (getline(std::cin, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            auto &lst = word_linenum[word];
            lst.push_back(linenum);
        }
        linenum++;
    }
    for (auto &w : word_linenum) {
        std::cout << w.first << " may occurs at line:" << std::endl;
        for (auto &n : w.second)
            std::cout << n << std::endl;
    }
    return 0;
}