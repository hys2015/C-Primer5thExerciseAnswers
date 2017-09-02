#include "exec13_19.h"

#include <iostream>

int exec13_19_main()
{
    Employee cc("copy_control");
    Employee cd(cc);
    Employee ce(cc);
    Employee cf("cf");
    std::cout << cc.getid() << " - "
        << cd.getid() << " - "
        << ce.getid() << " - "
        << cf.getid() << std::endl;
    return 0;
}