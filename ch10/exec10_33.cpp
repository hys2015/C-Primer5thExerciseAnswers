#include <iostream>
#include <iterator>
#include <vector>
#include <fstream>

void Solution1(std::ifstream &ifs, std::ostream &ofs1, std::ostream ofs2)
{
    std::istream_iterator<int> ifs_it(ifs), eof;
    std::ostream_iterator<int> ofs_it1(ofs1, " "), ofs_it2(ofs2, "\n");
    int input;
    while (ifs_it != eof)
    {
        input = *ifs_it++;
        if (input % 2)
            *ofs_it1++ = input;
        else
            *ofs_it2++ = input;
    }
}

void Solution2(std::ifstream &ifs, std::ostream &ofs1, std::ostream &ofs2)
{
    std::istream_iterator<int> ifs_it(ifs), eof;
    std::ostream_iterator<int> ofs_it1(ofs1, " "), ofs_it2(ofs2, "\n");
    int input;
    std::vector<int> odd, even;
    while (ifs_it != eof)
    {
        input = *ifs_it++;
        if (input % 2)
            odd.push_back(input);
        else
            even.push_back(input);
    }
    std::copy(odd.cbegin(), odd.cend(), ofs_it1);
    std::copy(even.cbegin(), even.cend(), ofs_it2);
    std::cout << "SOLUTION 2" << std::endl;
}

int exec10_33_main()
{
    std::string path_in("E:\\GitHubForks\\c++Primer5th-demo\\ch10\\exec10_33_in.txt");
    std::string path_out_1("E:\\GitHubForks\\c++Primer5th-demo\\ch10\\exec10_33_out1.txt");
    std::string path_out_2("E:\\GitHubForks\\c++Primer5th-demo\\ch10\\exec10_33_out2.txt");
    std::ifstream ifs(path_in);
    std::ofstream ofs1(path_out_1), ofs2(path_out_2);
    
    //Solution1(ifs, ofs1, ofs2);
    Solution2(ifs, ofs1, ofs2);
    ifs.close();
    ofs1.close();
    ofs2.close();
    return 0;
}
