#ifndef _STRBLOB_H_
#define _STRBLOB_H_

#include "StrBlobPtr.h"

#include <memory>

#include <vector>
#include <string>

class StrBlob{
public:
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size(){ return data->size(); }
    size_type size() const { return data->size(); }
    bool empty() { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    std::string& front();
    std::string& back();

    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

#endif