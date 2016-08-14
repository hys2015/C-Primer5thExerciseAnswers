/*
    Rewrite the program on page 481 using an allocator
*/

#include <string>
#include <memory>
#include <iostream>

int exec12_26_main()
{
    std::size_t n = 3;
    std::allocator<std::string> a;
    std::string *const p = a.allocate(n);
    std::string s;
    std::string *q = p;
    while (q != p + n && std::cin >> s)
        a.construct(q++, s);
    const std::size_t size = q - p;
    while (q != p)
        a.destroy(--q);
    a.deallocate(p, n);
    return 0;
}
