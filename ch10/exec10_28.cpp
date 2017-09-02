#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> vec({ 1,2,3,4,5,6,7,8,9 });
    std::list<int> back_ins, ins, front_ins;
    std::copy(vec.cbegin(), vec.cend(), std::back_inserter(back_ins));
    std::copy(vec.cbegin(), vec.cend(), std::inserter(ins, ins.begin()));
    std::copy(vec.cbegin(), vec.cend(), std::front_inserter(front_ins));
    return 0;
}