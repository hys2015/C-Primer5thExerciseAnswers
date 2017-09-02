#pragma once

#include <string>

class Employee {
public:
    Employee(const std::string &name) 
        : name_(name)
    {   
        id_ = inc++;
    }
    int getid() { return id_; }
private:
    std::string name_;
    int id_;
    static int inc;
};