#pragma once
#include <string>

class Employee {
public:
    Employee(const std::string &name)
        : name_(name)
    {
        id_ = inc++;
    }
    Employee(const Employee& e) 
        :name_(e.name_),
        id_(e.id_)
    { }
    Employee& operator=(const Employee& e) {
        this->name_ = e.name_;
        this->id_ = e.id_;
        return *this;
    }
    int getid() { return id_; }
    
private:
    std::string name_;
    int id_;
    static int inc;
};
