#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>

int exec10_29_main()
{
    std::string path("E:\\GitHubForks\\c++Primer5th-demo\\ch10\\exec10_29.txt");
    std::ifstream fs(path);
    if (fs.bad()) {
        std::cerr << "Opening file error: " << path << std::endl;
    }
    std::istream_iterator<std::string> if_it(fs);
    std::istream_iterator<std::string> eof;
    std::vector<std::string> vec;
    while (if_it != eof) {
        vec.push_back(*if_it++);
    }
    std::cout << "***OUT***" << std::endl;
    std::ostream_iterator<std::string> out_it(std::cout, "\n");
    std::copy(vec.begin(), vec.end(), out_it);
    return 0;
}