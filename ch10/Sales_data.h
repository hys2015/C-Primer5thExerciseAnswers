#ifndef _SALES_DATA_H_
#define _SALES_DATA_H_


#include <string>

class Sales_data{
public:
    Sales_data(const std::string &s) : bookNo(s){}
    std::string isbn() const{
        return bookNo;
    }
private:
    std::string bookNo;
};

#endif