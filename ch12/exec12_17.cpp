#include <memory>

int exec12_17_main()
{
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;
    //IntP p0(ix);
    //IntP p1(pi);  //undefined behavior
    IntP p2(pi2);
    //IntP p3(&ix); //local variable, undefined
    //IntP p4(new int(2048));
    IntP p5(p2.get());
    return 0;
}