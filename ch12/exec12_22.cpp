#include "StrBlob.h"
#include "ConstStrBlobPtr.h"

#include <iostream>

int exec12_22_main()
{
    const StrBlob cblob({ "C++", "Primer", "5th Edition" });

    ConstStrBlobPtr b_ptr(cblob);

    for (std::size_t i = 0; i < cblob.size(); ++i, b_ptr.incr())
    {
        std::cout << b_ptr.deref() << std::endl;
    }

    return 0;
}