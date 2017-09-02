#pragma once

#include <vector>
#include <list>

template <typename T, size_t N>
T* begin(T (&ar)[N]) {
    if (N > 0 ) return &ar[0];
    return nullptr;
}

template <typename T, size_t N>
T* end(T (&ar)[N]) {
    if (N > 0) return &ar[N-1];
    return nullptr;
}

//int main()
//{
//    float arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    float* p_b = begin(arr);
//    float* p_e = end(arr);
//    std::cout << *p_b << " - " << *p_e << std::endl;
//}
