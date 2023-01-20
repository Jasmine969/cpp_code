#ifndef VEC_H
#define VEC_H

#include <memory>
#include <utility>
#include <iostream>
#include <initializer_list>

using std::allocator;
using std::cout;
using std::initializer_list;
using std::pair;
using std::uninitialized_copy;

template <typename>
class Vec;
template <typename T>
bool operator==(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator<(const Vec<T> &, const Vec<T> &);

template <typename T>
class Vec
{
    friend bool operator== <T>(const Vec<T> &, const Vec<T> &);
    friend bool operator< <T>(const Vec<T> &, const Vec<T> &);

private:
    T *elements;
    T *first_free;
    T *cap;
    static allocator<T> alloc;
    // four utility functions
    void check_n_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    void reallocate();
    void reallocate(size_t n);
    pair<T *, T *> alloc_n_copy(const T *b, const T *e);
    void free();

public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vec(initializer_list<T>);
    Vec(const Vec &);            // copy constructor
    Vec &operator=(const Vec<T> &); // copy-assignment operator
    Vec(Vec &&);                 // move constructor
    Vec &operator=(Vec &&);      // move-assignment operator
    ~Vec();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    void push_back(const T &);
    T *begin() const { return elements; }
    T *end() const { return first_free; }
    void resize(size_t, const T &);
    void reserve(size_t);
    const T &operator[](size_t) const;
    T &operator[](size_t);
    Vec &operator=(initializer_list<T>);
};

template <typename T>
allocator<T> Vec<T>::alloc; // 一定要在类外定义一次静态变量

template <typename T>
Vec<T>::Vec(initializer_list<T> lst)
{
    auto ptr_pair = alloc_n_copy(lst.begin(), lst.end());
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
}

template <typename T>
void Vec<T>::push_back(const T &s)
{
    check_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
    auto ele = alloc.allocate(e - b);
    return {ele, uninitialized_copy(b, e, ele)};
}

template <typename T>
void Vec<T>::free()
{
    if (elements)
    {
        while (first_free != elements) // 书上用的if，创建了一个临时变量p
        {
            alloc.destroy(--first_free);
        }
        alloc.deallocate(elements, capacity()); // 书上没有用capacity，而是用cap-elements
    }
}

template <typename T>
Vec<T>::Vec(const Vec<T> &sv)
{
    auto ptr_pair = alloc_n_copy(sv.begin(), sv.end());
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
    cout << "copy constructor\n";
}

template <typename T>
Vec<T>::~Vec()
{
    free();
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec<T> &sv)
{
    auto ptr_pair = alloc_n_copy(sv.begin(), sv.end());
    free();
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
    return *this;
}

template <typename T>
Vec<T>::Vec(Vec &&sv)
    : elements(sv.elements), first_free(sv.first_free), cap(sv.cap)
{
    sv.elements = sv.first_free = sv.cap = nullptr;
    cout << "move constructor\n";
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs)
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

template <typename T>
void Vec<T>::reallocate()
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

template <typename T>
void Vec<T>::reallocate(size_t n)
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

template <typename T>
void Vec<T>::reserve(size_t n)
{
    if (capacity() < n)
    {
        reallocate(n);
    }
}

template <typename T>
void Vec<T>::resize(size_t n, const T &fill)
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

template <typename T>
const T &Vec<T>::operator[](size_t i) const
{
    return elements[i];
}

template <typename T>
T &Vec<T>::operator[](size_t i)
{
    return elements[i];
}

template <typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs)
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

template <typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs)
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

template <typename T>
Vec<T> &Vec<T>::operator=(initializer_list<T> il)
{
    auto ptr_pair = alloc_n_copy(il.begin(), il.end());
    free();
    elements = ptr_pair.first;
    first_free = cap = ptr_pair.second;
    return *this;
}

#endif