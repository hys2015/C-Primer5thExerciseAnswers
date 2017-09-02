
#include "Vec.h"

#include <iostream>

void testVec() 
{
    Vec<int> int_v;
    for (int i = 0; i < 10; ++i) {
        int_v.push_back(i);
    }
    std::cout << int_v.size() << std::endl;
    Vec<int> int_a(int_v);
    Vec<int> int_b = int_v;
    std::cout << int_a.size() << "-" << int_b.size() << std::endl;
}

//int main() {
//    testVec();
//    return 0;
//}