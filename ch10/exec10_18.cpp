#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

static std::string make_plural(int cnt, const std::string &s, const std::string &ending)
{
    return cnt > 1 ? s + ending : s;
}

static void elimDups(std::vector<std::string> &vec)
{
    std::sort(vec.begin(), vec.end());
    auto unique = std::unique(vec.begin(), vec.end());
    vec.erase(unique, vec.end());
}

static void biggies(std::vector<std::string> &words,
    std::vector<std::string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(),
        [](const std::string &lhs,
        const std::string &rhs)
    {
        return lhs.size() < rhs.size();
    }
    );

    auto wc = std::partition(words.begin(), words.end(),
        [sz](const std::string &s)
    {
        return s.size() < sz;
    }
    );

    auto count = wc - words.begin();
    std::cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" << std::endl;
    std::for_each(wc, words.end(), [](const std::string &s){std::cout << s << " "; });
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> words;
    std::vector<std::string>::size_type sz;
    std::cout << "enter your sz: ";
    std::cin >> sz;
    std::cout << "enter the words ^Z to end:";
    std::string input;
    while (std::cin >> input)
    {
        words.push_back(input);
    }
    biggies(words, sz);
    return 0;
}