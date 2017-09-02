#pragma once

#include <iostream>
#include <vector>

template <typename T, unsigned N>
void myprint( T (&array)[N])
{
    for (int i = 0; i < N; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

/*
int main()
{
    using namespace std;
    int arr[5] = { 1, 2, 3, 4, 5 };
    myprint(arr);
    return 0;
}
*/