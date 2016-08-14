/*
    Write a program that reads a string from the standard input into a
    dynamically allocated character array.Describe how your program handles
    varying size inputs. Test your program by giving it a string of data that
    is longer than the array size you've allocated.
*/

#include <iostream>

int exec12_24_main()
{
    int len;
    std::cout << "the length of string:";
    std::cin >> len;
    std::cin.ignore();
    char* str = new char[len + 1];
    std::cin.get(str, len + 1);  // store len - 1 elements
    std::cout << str << std::endl;
    return 0;
}