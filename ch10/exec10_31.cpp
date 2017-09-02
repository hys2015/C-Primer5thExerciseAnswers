#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main()
{
    std::cout << "enter integers ctrl+z to end: " << std::endl;
    std::istream_iterator<int> in_it(std::cin), eof;
    std::vector<int> vec(in_it, eof);
    std::sort(vec.begin(), vec.end());
    std::ostream_iterator<int> out_it(std::cout, " ");
    std::cout << "***UNIQUE ELEMENTS OUT***" << std::endl;
    std::unique_copy(vec.begin(), vec.end(), out_it);
    std::cout << std::endl;
    return 0;
}