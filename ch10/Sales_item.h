#pragma once
#ifndef _SALES_ITEM_H_
#define _SALES_ITEM_H_
#include <string>
#include <iostream>

class Sales_item {
    friend std::istream& operator>>(std::istream& is, Sales_item &item) {
        double price;
        is >> item.m_isbn >> item.unit_sold >> price;
        if (is) {
            item.revenue = item.unit_sold * price;
        }
        else {
            item = Sales_item();
        }
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, Sales_item &item) {
        os << item.m_isbn << " " << item.unit_sold << " " << item.revenue;
        return os;
    }
public:
    Sales_item():m_isbn(), unit_sold(0), revenue(0.0) {}
    Sales_item(const std::string isbn, int sold = 0, double revenue = 0.0): 
        m_isbn(isbn), unit_sold(sold), revenue(revenue){}
    std::string isbn() const { return m_isbn; }
    Sales_item& operator=(Sales_item &rhs) {
        this->m_isbn = rhs.m_isbn;
        this->unit_sold = rhs.unit_sold;
        this->revenue = rhs.revenue;
        return *this;
    }
    Sales_item operator+(const Sales_item &rhs) {
        this->unit_sold += rhs.unit_sold;
        this->revenue += rhs.revenue;
        return *this;
    }
private:
    std::string m_isbn;
    int unit_sold;
    double revenue;
};

#endif