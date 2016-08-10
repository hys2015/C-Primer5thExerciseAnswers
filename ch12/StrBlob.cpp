#include "StrBlob.h"

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>() ){ }
StrBlob::StrBlob(std::initializer_list<std::string> il):
    data(std::make_shared<std::vector<std::string>>(il)){ }

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
// testing
// main function
int StrBlobTest()
{
    StrBlob blob1;
    StrBlob blob2 = { "a", "b", "c" };
    blob1 = blob2;
    blob2.push_back("ddd");
    //blob1.data {"a", "b", "c", "ddd"}
    //blob2.data is the same as blob1's
    return 0;
}