#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    std::map<std::string, std::size_t> word_count;
    std::vector<std::string> exclude({ "hello", "world", "Hi" });
    std::string input;
    while (std::cin >> input) {
        if (std::find(exclude.begin(), exclude.end(), input) != exclude.end()) {
            std::cout << "excluded words !" << std::endl;
            continue;
        }
        std::size_t &count = ++word_count[input];
        std::cout << "word " << input << 
            " count increase successfully ("<< count << ")" << std::endl;
    }
    return 0;
}
