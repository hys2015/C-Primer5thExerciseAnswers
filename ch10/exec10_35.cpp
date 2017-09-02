#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main()
{
    std::istream_iterator<int> is_it(std::cin), eof;
    std::vector<int> vec(is_it, eof);
    for (std::vector<int>::iterator it = vec.end() - 1; it >= vec.begin(); it --) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}