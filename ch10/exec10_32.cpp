#include "Sales_item.h"

#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

static bool compareIsbn(Sales_item &lhs, Sales_item &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int exec10_32_main()
{
    std::istream_iterator<Sales_item> in_it(std::cin), eof;
    std::vector<Sales_item> vec(in_it, eof);
    std::sort(vec.begin(), vec.end(), compareIsbn);
    for (auto beg = vec.cbegin(), end = beg; end != vec.cend(); beg = end)
    {
        end = std::find_if(beg, vec.cend(), [beg](const Sales_item &item) {return beg->isbn() != item.isbn(); });
        std::cout << std::accumulate(beg, end, Sales_item()) << std::endl;
    }
    return 0;
}