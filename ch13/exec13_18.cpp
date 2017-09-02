#include "exec13_18.h"
#include <iostream>

int Employee::inc = 1;

int exec13_18_main()
{
    Employee a("aaa");
    Employee b("bbb");
    Employee c("ccc");
    std::cout << a.getid() << ":"
        << b.getid() << ":"
        << c.getid() << std::endl;
    return 0;
}