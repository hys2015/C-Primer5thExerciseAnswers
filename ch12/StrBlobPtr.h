#ifndef _STRBLOBPTR_H_
#define _STRBLOBPTR_H_

#include "StrBlob.h"

#include <vector>
#include <memory>
#include <string>

class StrBlob;  /////// incredibly important

class StrBlobPtr{
public:
    StrBlobPtr();
    StrBlobPtr(StrBlob &a, size_t sz = 0);
    std::string& deref() const;
    StrBlobPtr& incr();
protected:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif 