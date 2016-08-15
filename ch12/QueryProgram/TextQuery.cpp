#include "TextQuery.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

std::string make_plural(std::size_t ctr, const std::string &word,
    const std::string &end)
{
    return ctr > 1 ? word + end : word;
}

TextQuery::TextQuery(std::ifstream &ifs) :file(new std::vector<std::string>)
{
    std::string text;
    while (getline(ifs, text)){
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream iss(text);
        std::string word;
        while (iss >> word){
            auto &lines = wm[word];
            if (!lines){
                lines.reset(new std::set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const
{
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream & os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << std::endl;
    for (auto num : *qr.lines)
    {
        os << "\t (line " << num + 1 << ") "
            << *(qr.file->begin() + num) << std::endl;
    }
    return os;
}

int RunQuery()
{
    std::ifstream ifs;
    std::string path("E:\\GitHubForks\\c++Primer5th-demo\\ch12\\exec12_27\\exec12_27.txt");
    ifs.open(path, std::ios::in);
    if (ifs.bad()){
        std::cerr << "Open File: " << path << " error!" << std::endl;
        return -1;
    }
    TextQuery tq(ifs);
    while (true){
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
    return 0;
}