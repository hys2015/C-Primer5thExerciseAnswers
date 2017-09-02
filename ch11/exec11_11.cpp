#include <iostream>
#include <set>
#include "../ch10/Sales_data.h"

static bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return (lhs.isbn() < rhs.isbn());
}

int main()
{
    // using F = int(int*, int);     // F is a function type
    // using PF = int(*)(int*, int); // PF is a pointer to funtion

    using less_type = bool(*)(const Sales_data &, const Sales_data &); // pointer type
    std::multiset<Sales_data, less_type> s(compareIsbn);

    return 0;
}