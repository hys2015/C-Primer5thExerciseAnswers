#include "exec13_22.h"

int exec13_22_main()
{
    HasPtr p1("change me");
    HasPtr p2(p1);
    p1.setStr("changed");
    p1.setInt(100);
    HasPtr p3 = p2;
    p2.setStr("p2changed");
    p2.setInt(20);
    return 0;
}

void HasPtr::setStr(const std::string &s)
{
    ps->assign(s);
}

void HasPtr::setInt(int n)
{
    this->i = n;
}
