#include <iostream>
#include <map>
#include <string>

int exec11_31_main()
{
    std::multimap<std::string, std::string> author_title;
    author_title.insert({ "JohnBrown", "First Class Of Life" });
    author_title.insert({ "JohnBrown", "Second Class Of Life" });
    author_title.insert({ "KingCarrie", "C++ Primer" });
    author_title.insert({ "JohnBrown", "Third Class Of Life" });

    std::string keyword;
    std::cout << "enter name to display titles:" << std::endl;
    while (std::cin >> keyword)
    {
        auto beg = author_title.lower_bound(keyword),
            end = author_title.upper_bound(keyword);
        if (beg == end)
            std::cout << "not in the list" << std::endl;
        for (;
            beg != end; beg++)
        {
            std::cout << beg->first << " - "
                << beg->second << std::endl;
        }
    }

    return 0;
}