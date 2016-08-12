#include <memory>


int exec12_16_main()
{
    std::unique_ptr<int> u_ptr1(new int(100));
    std::unique_ptr<int> u_ptr2;
    u_ptr2.reset(u_ptr1.release());
    return 0;
}