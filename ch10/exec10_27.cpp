#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>


int exec10_27_main()
{
    std::vector<std::string> vec({ "abcd", "abc", "abcd", "xyz", "xyz", "a" });
    std::sort(vec.begin(), vec.end()); //required this
    std::list<std::string> lst;
    std::unique_copy(vec.cbegin(), vec.cend(), std::back_inserter(lst));
    std::list<std::string> rlst;
    std::unique_copy(vec.cbegin(), vec.cend(), std::front_inserter(rlst));

    return 0;
}