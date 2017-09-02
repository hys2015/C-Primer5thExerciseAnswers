#ifndef _EXEC13_26_H_
#define _EXEC13_26_H_

#include "../ch12/StrBlobPtr.h"

#include <memory>

#include <vector>
#include <string>

class StrBlob {
public:
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    StrBlob(const StrBlob &sb)
        :data(std::make_shared<std::vector<std::string>>(*sb.data)) {}
    StrBlob& operator=(const StrBlob &sb);

    size_type size() { return data->size(); }
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