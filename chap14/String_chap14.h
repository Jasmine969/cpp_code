#ifndef STRING_CHAP14_H
#define STRING_CHAP14_H

#include <memory>
#include <utility>
#include <initializer_list>
#include <cstring>
#include <iostream>

using std::allocator;
using std::initializer_list;
using std::ostream;
using std::pair;
using std::strlen;
using std::uninitialized_copy;

class String
{
    friend ostream &operator<<(ostream &os, const String &s);
    friend bool operator==(const String &, const String &);
    friend bool operator<(const String &, const String &);

private:
    char *elements;
    char *first_free;
    char *cap;
    static allocator<char> alloc;
    // four utility functions
    void check_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    void reallocate();
    void reallocate(size_t n);
    pair<char *, char *> alloc_n_copy(const char *b, const char *e);
    void free();

public:
    String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const char *);
    String(const String &);
    String &operator=(const String &);
    ~String();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void push_back(const char &);
    char *begin() const { return elements; }
    char *end() const { return first_free; }
    void resize(size_t, const char &);
    void reserve(size_t);
    char &operator[](size_t);
    const char &operator[](size_t) const;
};

allocator<char> String::alloc; // NOTE 一定要在类外定义一次静态变量

String::String(const char *cp)
{
    auto ptr_pair = alloc_n_copy(cp, cp + strlen(cp));
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
}

void String::push_back(const char &s)
{
    check_n_alloc();
    alloc.construct(first_free++, s);
}

pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto ele = alloc.allocate(e - b);
    return {ele, uninitialized_copy(b, e, ele)};
}

void String::free()
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

String::String(const String &sv)
{
    auto ptr_pair = alloc_n_copy(sv.begin(), sv.end());
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
}

String::~String()
{
    free();
}

String &String::operator=(const String &sv)
{
    auto ptr_pair = alloc_n_copy(sv.begin(), sv.end());
    free();
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
    return *this;
}

void String::reallocate()
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

void String::reallocate(size_t n)
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

void String::reserve(size_t n)
{
    if (capacity() < n)
    {
        reallocate(n);
    }
}

void String::resize(size_t n, const char &fill = '\0')
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

const char &String::operator[](size_t i) const
{
    return elements[i];
}

char &String::operator[](size_t i)
{
    return elements[i];
}

ostream &operator<<(ostream &os, const String &s)
{
    os << s.elements;
    return os;
}

bool operator==(const String &lhs, const String &rhs)
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

bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
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


#endif