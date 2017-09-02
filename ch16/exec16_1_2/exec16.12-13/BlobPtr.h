#pragma once

#include "Blob.h"
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

template <typename T> class BlobPtr;
template <typename T> bool operator < (const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T> bool operator == (const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr {

    friend bool operator < <T>(const BlobPtr &, const BlobPtr &);
    friend bool operator == <T>(const BlobPtr &, const BlobPtr &);

public:
    BlobPtr() : curr(0) {}
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(0) {
        check(sz, "BlobPtr initial position out of range");
        curr = sz;
    }
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    T* operator->() const {
        return & this->operator*();
    }
    //prefix inrease/decrease operator
    BlobPtr& operator++();
    BlobPtr& operator--();

    //postfix increase/decrease operator
    BlobPtr operator++(int);
    BlobPtr operator--(int);
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr; // current position within the array
};

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t cur, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret) {
        throw std::runtime_error("unbound BlobPtr");
    }
    else
        if (cur > ret->size()) {
            throw std::out_of_range(msg);
        }
    return ret;
}

template<typename T>
BlobPtr<T> & BlobPtr<T>::operator++()
{
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template<typename T>
BlobPtr<T> & BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "decrement past begin of BlobPtr");
    return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}

//////////////////////////////////////////////////////////////////////////
//operators
template <typename T>
bool operator < (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

template <typename T>
bool operator == (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

template <typename T>
bool operator != (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}

template <typename T>
bool operator > (const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return rhs < lhs;
}