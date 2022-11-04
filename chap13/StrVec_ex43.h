#ifndef STRVEC_EX43_H
#define STRVEC_EX43_H

#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <algorithm>

using std::allocator;
using std::for_each;
using std::initializer_list;
using std::pair;
using std::string;
using std::uninitialized_copy;

class StrVec
{
private:
    string *elements;
    string *first_free;
    string *cap;
    static allocator<string> alloc;
    // four utility functions
    void check_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    void reallocate();
    void reallocate(size_t n);
    pair<string *, string *> alloc_n_copy(const string *b, const string *e);
    void free();

public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string>);
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    ~StrVec();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void push_back(const string &);
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    void resize(size_t);
    void resize(size_t, const string &);
    void reserve(size_t);
    string &operator[](size_t);
};

allocator<string> StrVec::alloc; // NOTE 一定要在类外定义一次静态变量

StrVec::StrVec(initializer_list<string> lst)
{
    auto ptr_pair = alloc_n_copy(lst.begin(), lst.end());
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
}

void StrVec::push_back(const string &s)
{
    check_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto ele = alloc.allocate(e - b);
    return {ele, uninitialized_copy(b, e, ele)};
}

void StrVec::free()
{
    if (elements)
    {
        for_each(begin(), end(), [](const string &s)
                 { alloc.destroy(&s); });
        alloc.deallocate(elements, capacity()); // NOTE 书上没有用capacity，而是用cap-elements
    }
}

StrVec::StrVec(const StrVec &sv)
{
    auto ptr_pair = alloc_n_copy(sv.begin(), sv.end());
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
}

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &sv)
{
    auto ptr_pair = alloc_n_copy(sv.begin(), sv.end());
    free();
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
    return *this;
}

void StrVec::reallocate()
{
    auto newCapacity = size() ? 2 * size() : 1;
    auto const newData = alloc.allocate(newCapacity);
    auto ele = elements;
    auto dest = newData;
    for (size_t i = 0; i < size(); ++i)
    {
        alloc.construct(dest++, std::move(*ele++));
    }
    free();
    elements = newData;
    first_free = dest;
    cap = newData + newCapacity;
}

void StrVec::reallocate(size_t n)
{
    auto const newData = alloc.allocate(n);
    auto ele = elements;
    auto dest = newData;
    for (size_t i = 0; i < size(); ++i)
    {
        alloc.construct(dest++, std::move(*ele++));
    }
    free();
    elements = newData;
    first_free = dest;
    cap = newData + n;
}

void StrVec::reserve(size_t n)
{
    if (capacity() < n)
    {
        reallocate(n);
    }
}

void StrVec::resize(size_t n)
{
    /*
    1. n < size(): 删除多余的，destroy
    2. n > size(): push_back ""
    3. n = size(): 啥也不做
    */
    if (n < size())
    {
        while (size() > n)
        {
            alloc.destroy(--first_free);
        }
    }
    else if (n > size())
    {
        while (size() < n)
        {
            push_back("");
        }
    }
}

void StrVec::resize(size_t n, const string &fill)
{
    /*
    1. n < size(): 删除多余的，destroy
    2. n > size(): push_back ""
    3. n = size(): 啥也不做
    */
    if (n < size())
    {
        while (size() > n)
        {
            alloc.destroy(--first_free);
        }
    }
    else if (n > size())
    {
        while (size() < n)
        {
            push_back(fill);
        }
    }
}

string &StrVec::operator[](size_t i)
{
    return *(elements + i);
}

#endif