#ifndef _CONSTSTRBLOBPTR_H_
#define _CONSTSTRBLOBPTR_H_

#include <memory>

#include "StrBlobPtr.h"

class StrBlobPtr;
class ConstStrBlobPtr : public StrBlobPtr
{
public:
    ConstStrBlobPtr(const StrBlob &ca, std::size_t sz = 0);
private:

};

#endif

