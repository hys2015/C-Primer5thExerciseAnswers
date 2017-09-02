#pragma once
#include <string>
// HasPtr behave like a value
class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) 
        :ps(new std::string(s)), i(0)
    {}
    HasPtr(const HasPtr& rhs)
        : ps(new std::string(*rhs.ps)),
        i(i)
    {}
        
    HasPtr& operator=(const HasPtr &rhs)
    {
        auto newp = new std::string(*rhs.ps);
        delete ps;
        this->ps = newp;
        this->i = rhs.i;
        return *this;
    }
    ~HasPtr()
    {
        delete ps;
    }
    void setStr(const std::string&);
    void setInt(int n);
private:
    std::string *ps;
    int i;
};