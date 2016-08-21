#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Sales_data.h"

bool compareIsbn(Sales_data &lhs, Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int exec10_12_main()
{
    std::vector<Sales_data> vec;
    Sales_data s1("isbn1"), s2("abcd"), s3("ciend");
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);

    std::sort(vec.begin(), vec.end(), compareIsbn);
    
    return 0;
}