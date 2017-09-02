#include <list>
#include <vector>
#include <map>

int main()
{
    // declared fine
    std::map<std::vector<int>::iterator, int> map1;
    std::map<std::list<int>::iterator, int> map2;

    std::vector<int> vec;
    std::list<int> lst;
    // fine
    map1.insert(std::pair<std::vector<int>::iterator, int>(vec.begin(), 0));
    // error: compiler complains that list<int>::iterator has no operator <
    //map2.insert(std::pair<std::list<int>::iterator, int>(lst.begin(), 0));

    return 0;
}