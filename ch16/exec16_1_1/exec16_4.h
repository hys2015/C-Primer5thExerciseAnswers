#pragma once

#include <vector>
#include <list>

template <typename InputIterator, typename V>
InputIterator myfind(InputIterator first, InputIterator last, const V &value) 
{
    while (first != last) {
        if (*first == value) return first;
        ++first;
    }
    return last;
}
/*
int main()
{
    using namespace std;
    vector<int> vec(10, -1);
    const int idx = 5;
    const int val = 100;
    vec[idx] = val;
    auto idx1 = myfind(vec.begin(), vec.end(), val);
    cout << idx << " - " << idx1 - vec.begin() << endl;

    list<string> lst(10, "str");
    auto it = lst.begin();
    int i = 0;
    while (i++ < idx) {
        it++;
    }
    const string str = "changed";
    *it = str;
    auto idx2 = myfind(lst.begin(), lst.end(), str);
    cout << ((idx2 == it) ? "TRUE" : "FALSE") << endl;
    return 0;
}
*/