#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <iostream>

int exec10_37_main()
{
    std::vector<int> vec({ 1,2,3,4,5,6,7,8,9,10 });
    std::list<int> lst;
    /*for (auto it = vec.cbegin(); it < vec.cend(); it++) {
        lst.push_back(*it);
    }*/
    std::copy(vec.crbegin() + 3, vec.crbegin() + 8, std::back_inserter(lst)); // 3rd to 7th elments :[3..8) equals (2, 7] in reverse.  
    for (auto n : lst) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}