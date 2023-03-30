#ifndef STRVEC_CHAP14_H
#define STRVEC_CHAP14_H

#include <string>
#include <memory>
#include <utility>
#include <iostream>
#include <initializer_list>

using std::allocator;
using std::cout;
using std::initializer_list;
using std::pair;
using std::string;
using std::uninitialized_copy;

class StrVec
{
    friend bool operator==(const StrVec &, const StrVec &);
    friend bool operator<(const StrVec &, const StrVec &);

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
    StrVec(const StrVec &);            // copy constructor
    StrVec &operator=(const StrVec &); // copy-assignment operator
    StrVec(StrVec &&);                 // move constructor
    StrVec &operator=(StrVec &&);      // move-assignment operator
    ~StrVec();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void push_back(const string &);
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    void resize(size_t, const string &);
    void reserve(size_t);
    const string &operator[](size_t) const;
    string &operator[](size_t);
    StrVec &operator=(initializer_list<string>);
};

allocator<string> StrVec::alloc; // NOTE 一定要在类外定义一次静态变量

StrVec::StrVec(initializer_list<string> lst)
{
    auto ptr_pair = alloc_n_copy(lst.begin(), lst.end());
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
    cout << "copy constructor\n";
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
        while (first_free != elements) // NOTE 书上用的if，创建了一个临时变量p
        {
            alloc.destroy(--first_free);
        }
        alloc.deallocate(elements, capacity()); // NOTE 书上没有用capacity，而是用cap-elements
    }
}

StrVec::StrVec(const StrVec &sv)
{
    auto ptr_pair = alloc_n_copy(sv.begin(), sv.end());
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
    cout << "copy constructor\n";
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
    cout << "copy assignment\n";
    return *this;
}

StrVec::StrVec(StrVec &&sv)
    : elements(sv.elements), first_free(sv.first_free), cap(sv.cap)
{
    sv.elements = sv.first_free = sv.cap = nullptr;
    cout << "move constructor\n";
}

StrVec &StrVec::operator=(StrVec &&rhs)
{
    if (this != &rhs) // 如果自赋值，直接return，否则移动操作
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    cout << "move-assignment\n";
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

void StrVec::resize(size_t n, const string &fill = "")
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

const string &StrVec::operator[](size_t i) const
{
    return elements[i];
}

string &StrVec::operator[](size_t i)
{
    return elements[i];
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (size_t i = 0; i != lhs.size(); ++i)
    {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    size_t sz1 = lhs.size(), sz2 = rhs.size(),
           min_sz = (sz1 > sz2) ? sz2 : sz1;
    for (size_t i = 0; i != min_sz; ++i)
    {
        // 只要出现不等的元素，立即返回结果；否则比较下一位
        if (lhs[i] != rhs[i])
        {
            return lhs[i] < rhs[i];
        }
    }
    // 之前的全部相等，比较长度
    return sz1 < sz2;
}

StrVec &StrVec::operator=(initializer_list<string> il)
{
    auto ptr_pair = alloc_n_copy(il.begin(), il.end());
    free();
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
    return *this;
}

#endif