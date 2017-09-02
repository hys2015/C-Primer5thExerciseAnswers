#include <utility>
#include <string>

int main()
{
    std::string str("CppPrimer");
    int num = 1;
    std::pair<std::string, int> pair1(str, num);
    std::pair<std::string, int> pair2 = { str, num };
    std::pair<std::string, int> pair3{ str, num };
    std::pair<std::string, int> pair4 = std::make_pair(str, num) ;
    return 0;
}