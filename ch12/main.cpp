#include "Strblob.h"

#include <vector>
#include <string>

int main()
{
    StrBlob blob1;
    StrBlob blob2 = { "a", "b", "c" };
    blob1 = blob2;
    blob2.push_back("ddd");
    //blob1.data {"a", "b", "c", "ddd"}
    //blob2.data is the same as blob1's
    return 0;
}