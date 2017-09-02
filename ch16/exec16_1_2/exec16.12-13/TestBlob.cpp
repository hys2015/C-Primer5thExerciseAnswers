#include "Blob.h"
#include "BlobPtr.h"

#include <iostream>

void print(const std::string &s) {
    std::cout << s << std::endl;
}

void print(int a) {
    std::cout << a << std::endl;
}

void testBlob()
{
    //testBlob
    Blob<int> int_b;
    Blob<int> int_b_il({ 1, 2, 3, 4, 5 });
    int a = int_b_il.back();
    print(a);
    Blob<std::string> str_b;
    Blob<std::string> str_b_il({ "cpp", "primer", "5th" });
    auto str = str_b_il.front();
    print(str);
    str_b_il.pop_back();
    str = str_b_il.back();
    print(str);
    print(str_b_il[0]);

    //test BlobPtr
    print("===testBlobPtr===");
    BlobPtr<int> int_bptr(int_b_il);
    BlobPtr<std::string> str_bptr(str_b_il);
    print(*str_bptr++);
    print(*str_bptr--);
    print(*++str_bptr);
    print(*--str_bptr);

    print("===testBlobPtrOperator===");
    BlobPtr<int> int_bptr1 = int_bptr;
    print(int_bptr1 == int_bptr);
    print(int_bptr1 < ++int_bptr);
}

//void main()
//{
//    testBlob();
//}