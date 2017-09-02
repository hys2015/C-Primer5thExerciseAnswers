#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
    std::list<int> lst({1,0,3,4,5,6,7,2,0,3,2,1});
    auto idx = std::find(lst.rbegin(), lst.rend(), 0);
    for (auto it = idx.base(); it != lst.cend(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}