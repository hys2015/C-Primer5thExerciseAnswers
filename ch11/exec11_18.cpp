#include <map>
#include <string>
#include <utility>
int exec11_18_main()
{
    std::map<std::string, int> word_count;
    std::map<std::string, int>::const_iterator map_it = word_count.cbegin();
    return 0;
}