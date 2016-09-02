#include <iostream>
#include <set>
#include "../ch10/Sales_data.h"
static bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return (lhs.isbn() < rhs.isbn());
}
int exec11_19_main()
{
    std::multiset<Sales_data, bool(*)(const Sales_data &, const Sales_data &)> bookstore;
    //OR:
    //using func_type = bool(*)(const Sales_data&, const Sales_data &);
    //std::multiset<Sales_data, func_type> bookstore;

    return 0;
}