#include <map>


int main()
{
    std::map<int, float> map;
    std::map<int, float>::key_type idx;
    std::map<int, float>::mapped_type val = map[idx];

    return 0;
}