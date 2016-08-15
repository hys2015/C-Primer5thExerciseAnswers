#ifndef _EXEC12_27_H_
#define _EXEC12_27_H_

#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <memory>

class MyQueryResult;

class MyTextQuery{
public:
    typedef std::vector<std::string>::size_type line_no;
    MyTextQuery(){ };
    MyTextQuery(std::filebuf&);
    MyQueryResult query(std::string& );
private:
    std::map<std::string, std::set<line_no>> m_word_map; // word->line_no set map
    //the following map is not necessary , vector is more proper.
    std::map<line_no, std::string> m_line_map; // line_no -> line content map

};

class MyQueryResult{
public:
    MyQueryResult(std::shared_ptr<std::set<MyTextQuery::line_no>>,
                  std::shared_ptr<std::map<MyTextQuery::line_no, std::string>>);
    void print();
private:
    std::shared_ptr<std::set<MyTextQuery::line_no>> m_ptr;
    std::shared_ptr<std::map<MyTextQuery::line_no, std::string>> m_map_ptr;
};

#endif
