#include "exec12_27.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <set>

MyTextQuery::MyTextQuery(std::filebuf &ifs)
{
    std::string line;
    std::istream is(&ifs);
    std::size_t line_num = 1;
    while (getline(is, line)){
        std::istringstream iss(line);
        std::string word;
        while (iss >> word){
            std::set<line_no> word_set = m_word_map[word];
            word_set.insert(line_num);
            m_word_map[word] = word_set;
        }
        m_line_map[line_num] = line;
        line_num++;
    }
}

MyQueryResult MyTextQuery::query(std::string &keyword)
{
    std::shared_ptr<std::set<MyTextQuery::line_no>> p = std::make_shared<std::set<MyTextQuery::line_no>>(m_word_map[keyword]);
    std::shared_ptr<std::map<MyTextQuery::line_no, std::string>> q =
        std::make_shared < std::map<MyTextQuery::line_no, std::string> >(m_line_map) ;
    MyQueryResult result(p, q);
    return result;
}

MyQueryResult::MyQueryResult(std::shared_ptr<std::set<MyTextQuery::line_no>> p,
    std::shared_ptr<std::map<MyTextQuery::line_no, std::string>> q)
{
    m_ptr = p;
    m_map_ptr = q;
}

void MyQueryResult::print()
{
    if (m_ptr == NULL){
        std::cerr << "MyQueryResult m_ptr is NULL!" << std::endl;
        return;
    }
    for (std::set<MyTextQuery::line_no>::iterator it = m_ptr->begin(); it != m_ptr->end(); it++)
    {
        MyTextQuery::line_no idx = *it;
        std::cout << "( line " << idx << " ): "
            << m_map_ptr->at(idx) << std::endl;
    }
    std::cout << std::endl;
}

int exec12_27_main()
{
    std::filebuf fbuf;
    std::string path("E:/GitHubForks/c++Primer5th-demo/ch12/exec12_27/exec12_27.txt");
    if (fbuf.open(path, std::ios::in) == NULL)
    {
        std::cout << "Can't Open File." << std::endl;
        return -1;
    }
    MyTextQuery query(fbuf);
    std::cout << "Query Text in file: " << path << std::endl;
    std::cout << "Input the text you want to query or q to quit." << std::endl;

    std::string key;
    while (std::cin >> key)
    {
        if (1 == key.length() && key[0] == 'q') break;
        MyQueryResult mqr = query.query(key);
        mqr.print();
    }
    return 0;
}