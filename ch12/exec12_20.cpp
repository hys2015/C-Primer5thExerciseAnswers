#include "StrBlob.h"
#include "StrBlobPtr.h"

#include <fstream>
#include <iostream>
#include <string>

int main()
{
    StrBlob blob;

    std::filebuf fbuf;
    if (fbuf.open("E:/GitHubForks/c++Primer5th-demo/ch12/input.txt", std::ios::in) == NULL)
    {
        std::cout << "opening file error" << std::endl;
        return -1;
    }
    std::istream in(&fbuf);
    std::string input;
    while (getline(in, input))
    {
        blob.push_back(input);
    }
    //output content
    StrBlobPtr blob_ptr = blob.begin();
    for (std::size_t i = 0; i < blob.size(); ++i, blob_ptr.incr())
    {
        std::cout << blob_ptr.deref() << std::endl;
    }

    return 0;
}