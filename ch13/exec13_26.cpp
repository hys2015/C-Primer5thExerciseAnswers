#include "exec13_26.h"

StrBlob & StrBlob::operator=(const StrBlob & sb)
{
    data = std::make_shared<std::vector<std::string>>(*sb.data);
    return *this;
}

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
StrBlob::StrBlob(std::initializer_list<std::string> il) :
    data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const
{
    if (i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}

std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

int main()
{
    StrBlob sb({"a", "b", "c"});
    StrBlob sb1(sb);
    sb.push_back("abcd");
    StrBlob sb2 = sb;
    sb.push_back("xyz");
    return 0;
}