#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

std::map<std::string, std::string> buildMap(std::ifstream &map_file)
{
    std::map<std::string, std::string> trans_map;
    std::string line;
    std::string word;
    while (map_file >> word && std::getline(map_file, line))
    {
        if (line.size() > 1)
            trans_map[word] = line.substr(1);
        else
            throw std::runtime_error("no rule for " + word);
    }
    return trans_map;
}

const std::string& transform(const std::string &s, const std::map<std::string, std::string> &map)
{
    auto map_it = map.find(s);
    if (map_it != map.end())
    {
        return map_it->second;
    }
    else {
        return s;
    }
}

void word_transform(std::ifstream &map_file, std::ifstream &input)
{
    auto trans_map = buildMap(map_file);
    std::string text;
    while (std::getline(input, text))
    {
        std::istringstream iss(text);
        std::string word;
        bool firstWord = true;
        while (iss >> word)
        {
            if (firstWord)
                firstWord = false;
            else
                std::cout << " ";
            std::cout << transform(word, trans_map);
        }
        std::cout << std::endl;
    }
}

int exec11_33_main()
{
    std::ifstream rule_file("E:\\GitHubForks\\c++Primer5th-demo\\ch11\\exec11_33\\map_rules.txt");
    std::ifstream input_file("E:\\GitHubForks\\c++Primer5th-demo\\ch11\\exec11_33\\input.txt");
    word_transform(rule_file, input_file);
    return 0;
}