#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Sales_data.h"

int exec10_17_main()
{
    std::vector<Sales_data> vec;
    Sales_data s1("abcde"), s2("aaa"), s3("xyz");
    vec.push_back(s1);
    vec.push_back(s2);
    vec.push_back(s3);

    std::sort(vec.begin(), vec.end(), 
        [](Sales_data &lhs, Sales_data &rhs){
            return lhs.isbn() < rhs.isbn();
        }
    );

    return 0;
}