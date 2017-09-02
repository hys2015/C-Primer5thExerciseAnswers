/*
    Write a program to concatenate two string literals, putting the result
    in a dynamically allocated array of char. Write a program to concatenate
    two library strings that have the same value as the literals used in the 
    first program.
*/


#include <memory>
#include <new>
#include <string>
#include <iostream>

std::size_t strlen(char *s)
{
    int n = 0;
    while (s[n] != '\0')
    {         
        n++;
    }
    return n;
}

char* concat_dynamic_alloc(const char *s1, const char *s2)
{
    std::size_t len1 = strlen(s1), len2 = strlen(s2);
    char *ret = new char[len1 + len2 + 1];
    for (size_t i = 0; i < len1; ++i)
    {
        ret[i] = s1[i];
    }
    for (size_t n = len1, i = 0; i < len2; ++n, ++i)
    {
        ret[n] = s2[i];
    }
    ret[len1 + len2] = '\0';
    return ret;
}

std::string concat_libstring(std::string &s1, std::string &s2)
{
    char *s = concat_dynamic_alloc(s1.c_str(), s2.c_str());
    return std::string(s);
}

int main()
{
    char *sa = "abcdef";
    char *sb = "xyzzzz";
    char *ed = concat_dynamic_alloc(sa, sb);
    std::cout << ed << std::endl;

    std::string s1("abbbbbb");
    std::string s2("xyyy");
    std::cout << concat_libstring(s1, s2) << std::endl;

    return 0;
}