#include "ConstStrBlobPtr.h"

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &ca, std::size_t sz):
    StrBlobPtr()
{
    wptr = ca.data;
    curr = sz;
}