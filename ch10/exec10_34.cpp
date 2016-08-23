#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int exec10_34_main()
{
    std::istream_iterator<int> is_it(std::cin), eof;
    std::vector<int> vec(is_it, eof);
    std::ostream_iterator<int> os_it(std::cout, " ");
    std::copy(vec.crbegin(), vec.crend(), os_it);

    return 0;
}