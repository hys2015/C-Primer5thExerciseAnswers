#include <map>
#include <utility>
#include <vector>

int main()
{
    std::map<int, std::vector<int>>::key_type type1; // int
    std::map<int, std::vector<int>>::mapped_type type2; // vector<int>
    std::map<int, std::vector<int>>::value_type type3; // pair<int, vector<int>>

    return 0;
}