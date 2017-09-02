#pragma once

#define  _SCL_SECURE_NO_WARNINGS

#include <vector>
#include <memory>
#include <utility>
#include <map>

template <typename T>
class Vec {
    typedef std::size_t size_t;
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr){
    }
    Vec(const Vec &);
    Vec& operator=(const Vec&);
    ~Vec();

    void push_back(const T&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T* begin() const { return elements; }
    T* end() const { return first_free; }
private:
    static std::allocator<T> alloc;

    void chk_n_alloc() {
        if (size() == capacity()) reallocate();
    }
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);

    void free();
    void reallocate();

    T *elements;        //pointer to the first element in the array
    T *first_free;      //pointer to the first free element in the array
    T *cap;             //pointer to one past the end of the array
};

template <typename T>
Vec<T>::Vec(const Vec &v) {
    auto newdata = alloc_n_copy(v.begin(), v.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template<typename T>
Vec<T>::~Vec()
{
    free();
}

template<typename T>
void Vec<T>::push_back(const T &v)
{
    chk_n_alloc();
    alloc.construct(first_free++, v);
}

template<typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *first, const T *last)
{
    auto data = alloc.allocate(last - first);
    return{ data, std::uninitialized_copy(first, last, data) };
}

template<typename T>
void Vec<T>::free()
{
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

template<typename T>
void Vec<T>::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;

    auto newdata = alloc.allocate(newcapacity);

    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

//////////////////////////////////////////////////////////////////////////
//declaration for static member
template <typename T> std::allocator<T> Vec<T>::alloc;

