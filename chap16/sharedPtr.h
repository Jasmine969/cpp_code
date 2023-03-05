#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <functional>
using std::function;

#include <iostream>
using std::cout;

template <typename T>
class sharedPtr
{
private:
    T *p;
    unsigned *uc;
    function<void(T *)> del;
    bool verbose;

public:
    sharedPtr(bool vb = false)
        : p(nullptr), uc(nullptr), del(nullptr), verbose(vb) {}
    explicit sharedPtr(T *ptr, bool vb = false)
        : p(ptr), uc(new unsigned(1)), del(nullptr), verbose(vb) {}
    explicit sharedPtr(T *ptr, function<void(T *)> deleter, bool vb = false)
        : p(ptr), uc(new unsigned(0)), del(deleter), verbose(vb) {}
    sharedPtr(const sharedPtr &);
    sharedPtr(sharedPtr &&) noexcept;
    sharedPtr &operator=(const sharedPtr &);
    sharedPtr &operator=(sharedPtr &&) noexcept;
    ~sharedPtr();

    unsigned use_count() { return *uc; }
    void reset();
    void reset(T *);
    void reset(T *, function<void(T *)>);
    T &operator*() { return *p; }
    T &operator*() const { return *p; }
    T *operator->() { return &**this; }
    T *operator->() const { return &**this; }
};

template <typename T>
sharedPtr<T>::sharedPtr(const sharedPtr &sp)
    : p(sp.p), uc(sp.uc), del(sp.del)
{
    if (uc) // 必须保证uc不是nullptr，才能进行下一行的解引用
        ++*uc;
}

template <typename T>
sharedPtr<T>::sharedPtr(sharedPtr &&sp) noexcept
    : p(sp.p), uc(sp.uc), del(sp.del)
{
    sp.p = nullptr;
    sp.uc = nullptr;
}

template <typename T>
sharedPtr<T>::~sharedPtr()
{
    if (uc && --*uc == 0)
    {
        del ? del(p) : delete p;
        delete uc;
    }
}

template <typename T>
sharedPtr<T> &sharedPtr<T>::operator=(const sharedPtr &rhs)
{
    ++*rhs.uc;
    this->~sharedPtr();
    p = rhs.p;
    uc = rhs.uc;
    del = rhs.del;
    if (verbose)
        cout << "copy assignment operator\n";
    return *this;
}

template <typename T>
sharedPtr<T> &sharedPtr<T>::operator=(sharedPtr &&rhs) noexcept
{
    if (this != &rhs)
    {
        this->~sharedPtr();
        p = rhs.p;
        uc = rhs.uc;
        del = rhs.del;
        rhs.p = nullptr;
        rhs.uc = nullptr;
    }
    if (verbose)
        cout << "move assignment operator\n";
    return *this;
}

template <typename T>
void sharedPtr<T>::reset()
{
    this->~sharedPtr();
    p = nullptr;
}

template <typename T>
void sharedPtr<T>::reset(T *q)
{
    if (p != q) // 如果不判断，出现自赋值，析构时会出现空悬指针
    {
        this->~sharedPtr();
        p = q;
        uc = new unsigned(1);
    }
}

template <typename T>
void sharedPtr<T>::reset(T *q, function<void(T *)> deleter)
{
    if (p != q)
    {
        this->~sharedPtr();
        p = q;
        uc = new unsigned(1);
        del = deleter;
    }
}

#endif