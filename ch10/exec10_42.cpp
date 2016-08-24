#include <list>
#include <algorithm>
#include <string>
#include <iostream>

int exec10_42_main()
{
    std::list<int> lst({ 1,1,3,4,5,6,7,8,5,6,9 });
    lst.sort();
    lst.unique();
    return 0;
}