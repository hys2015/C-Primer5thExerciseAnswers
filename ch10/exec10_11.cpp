#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::ostream& print_vec(std::ostream &os, const std::vector<std::string> &vec)
{
    os << "\t **print_vec:**" << std::endl;
    for (auto elm : vec) {
        os << elm << std::endl;
    }
    return os;
}

bool isShorter(const std::string &lhs, const std::string &rhs)
{
    return lhs.size() < rhs.size();
}

static void elimDups(std::vector<std::string> &vec)
{
    print_vec(std::cout, vec);
    //std::sort(vec.begin(), vec.end());
    std::stable_sort(vec.begin(), vec.end(), isShorter);

    print_vec(std::cout, vec);
    auto unique = std::unique(vec.begin(), vec.end());

    print_vec(std::cout, vec);  // has blank after the element to which unique points
    vec.erase(unique, vec.end());

    print_vec(std::cout, vec);
}

int main()
{
    std::vector<std::string> vec;
    std::string input;
    while (std::cin >> input){
        vec.push_back(input);
    }
    elimDups(vec);
    return 0;
}