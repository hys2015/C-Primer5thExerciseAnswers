/*
    exercise 12.32 and exercise 12.33
*/

#include "exec12_32.h"

#include <sstream>
#include <iostream>

static std::string make_plural(std::size_t size, const std::string &str, const std::string &ending)
{
    return size > 1 ? str + ending : str;
}

BlobTextQuery::BlobTextQuery(std::ifstream &ifs) :file(new StrBlob)
{
    std::string text;
    while (getline(ifs, text)){
        file->push_back(text);
        line_no n = file->size() - 1;
        std::istringstream iss(text);
        std::string word;
        while (iss >> word)
        {
            std::shared_ptr<std::set<line_no>> &line = wm[word];
            if (!line){
                line.reset(new std::set<line_no>);
            }
            line->insert(n);
        }
    }
}


BlobQueryResult BlobTextQuery::query(const std::string &key) const
{
    static std::shared_ptr<std::set<line_no>> no_data = std::make_shared<std::set<line_no>>();
    auto loc = wm.find(key);
    if (loc == wm.end())
        return BlobQueryResult(key, no_data, file);
    else
        return BlobQueryResult(key, loc->second, file);
}

std::ostream& print(std::ostream& os, const BlobQueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << std::endl;
    for (auto num : *qr.lines){
        os << "\t (line " << num + 1 << ") ";
        auto it = qr.file->begin();
        while (num--){
            it.incr();
        }
        os << it.deref() << std::endl;
    }
    return os;
}

std::set<BlobTextQuery::line_no>::iterator BlobQueryResult::begin()
{
    return lines->begin();
}

std::set<BlobTextQuery::line_no>::iterator BlobQueryResult::end()
{
    return lines->end();
}


std::shared_ptr<StrBlob> BlobQueryResult::get_file()
{
    return file;
}

int main()
{
    std::ifstream ifs;
    std::string path("E:\\GitHubForks\\c++Primer5th-demo\\ch12\\exec12_27\\exec12_27.txt");
    ifs.open(path, std::ios::in);
    if (ifs.bad())
    {
        std::cerr << "Open file error." << std::endl;
    }
    BlobTextQuery btq(ifs);
    std::string input;
    while (true)
    {
        std::cout << " input text to look for or q to quit: ";
        if (!(std::cin >> input) || input == "q") break;
        print(std::cout, btq.query(input));
    }
    return 0;
}