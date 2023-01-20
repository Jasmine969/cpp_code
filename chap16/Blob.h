#ifndef BLOB_H
#define BLOB_H

#include <vector>
using std::vector;

#include <memory>
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

#include <string>
using std::string;

#include <initializer_list>
using std::initializer_list;

#include <stdexcept>
using std::out_of_range;
using std::runtime_error;

#include <iostream>
using std::cout;

const string RED = "\033[0;41;37m";
const string WHITE = "\033[0;40;37m";

// forward declaration
template <typename>
class BlobPtr;
template <typename>
class Blob;
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator<(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T> &lhs, const Blob<T> &rhs);
    friend bool operator< <T>(const Blob<T> &lhs, const Blob<T> &rhs);

public:
    typedef typename vector<T>::size_type size_type;
    Blob() : data(make_shared<vector<T>>()){};
    Blob(initializer_list<T> i1) : data(make_shared<vector<T>>(i1)){};
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    T &front();
    T &back();
    T &front() const;
    T &back() const;
    void push_back(const T &s)
    {
        data->push_back(s);
        cout << "copy push\n";
    }
    void push_back(T &&s)
    {
        data->push_back(std::move(s));
        cout << "move push\n";
    }
    void pop_back();
    BlobPtr<T> begin();
    BlobPtr<T> end();
    T &operator[](size_t);
    const T &operator[](size_t) const;

private:
    shared_ptr<vector<T>> data;
    void check(size_type, const string &) const;
};

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const
{
    if (data->size() <= i)
    {
        throw out_of_range(msg);
    }
}

template <typename T>
T &Blob<T>::front()
{
    check(0, "front on an empty Blob.");
    return data->front();
}

template <typename T>
T &Blob<T>::back()
{
    check(0, "back on an empty Blob.");
    return data->back();
}

template <typename T>
T &Blob<T>::front() const
{
    check(0, "front on an empty Blob.");
    return data->front();
}

template <typename T>
T &Blob<T>::back() const
{
    check(0, "back on an empty Blob.");
    return data->back();
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on an empty Blob.");
    data->pop_back();
}

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *lhs.data == *rhs.data;
}

template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return *lhs.data < *rhs.data;
}

template <typename T>
T &Blob<T>::operator[](size_t i)
{
    return (*data)[i];
}

template <typename T>
const T &Blob<T>::operator[](size_t i) const
{
    return (*data)[i];
}

template <typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
BlobPtr<T> operator+(BlobPtr<T>, int);

template <typename T>
BlobPtr<T> operator+(int, BlobPtr<T>);

template <typename T>
BlobPtr<T> operator-(BlobPtr<T>, int);
template <typename T>
class BlobPtr
{
    friend bool operator==<T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend bool operator< <T>(const BlobPtr<T> &, const BlobPtr<T> &);
    friend BlobPtr<T> operator+<T>(BlobPtr<T>, int);
    friend BlobPtr<T> operator+<T>(int, BlobPtr<T>);
    friend BlobPtr<T> operator-<T>(BlobPtr<T>, int);

private:
    typedef typename Blob<T>::size_type size_type;
    size_type curr;
    weak_ptr<vector<T>> wp;
    shared_ptr<vector<T>> check(size_type, const string &msg) const;

public:
    BlobPtr() : curr(0){};
    BlobPtr(Blob<T> &sb, size_type i = 0) : wp(sb.data), curr(i){};
    T &operator[](size_t);
    const T &operator[](size_t) const;
    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
    BlobPtr &operator+=(int);
    BlobPtr &operator-=(int);
    T &operator*() const;
    T *operator->() const;
};

template <typename T>
shared_ptr<vector<T>>
BlobPtr<T>::check(size_type i, const string &msg) const
{
    // 先检查vector是否存在
    auto p = wp.lock();
    if (!p)
        throw runtime_error("Unbounded BlobPtr");
    // 再检查下标是否越界，接受off-the-end pointer
    if (i > p->size())
        throw out_of_range(msg);
    return p;
}

template <typename T>
T &BlobPtr<T>::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template <typename T>
T *BlobPtr<T>::operator->() const
{
    // return & this->operator*();
    return &**this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    ++curr;
    check(curr, "increment past end");
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    --curr; // 如果本来是0，则递减后变成一个超大的数，下一行抛出error
    check(curr, "decrement past the begin");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this; // NOTE 已经进入类的作用域了，无需再提供模板实参了
    // 上一行代码与 BlobPtr<T> ret = *this; 效果相同 （P588）
    ++*this; // check
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this; // check
    return ret;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator+=(int dist)
{
    curr += dist;
    check(curr, "increment past the end");
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator-=(int dist)
{
    curr -= dist;
    check(curr, "increment past the end");
    return *this;
}

template <typename T>
BlobPtr<T> operator+(BlobPtr<T> p, int dist)
{
    p += dist;
    return p;
}

template <typename T>
BlobPtr<T> operator+(int dist, BlobPtr<T> p)
{
    return p + dist;
}

template <typename T>
BlobPtr<T> operator-(BlobPtr<T> p, int dist)
{
    p -= dist;
    return p;
}

template <typename T>
inline bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    auto p1 = lhs.wp.lock(), p2 = rhs.wp.lock();
    if (p1 == p2) // vector<T>的地址相等
    {
        return (lhs.curr == rhs.curr) || !p1; // 位置也相等或者两个都是空的，就认为指针相等
    }
    return false;
}

template <typename T>
inline bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
BlobPtr<T> Blob<T>::begin()
{
    return BlobPtr<T>(*this);
}

template <typename T>
BlobPtr<T> Blob<T>::end()
{
    return BlobPtr<T>(*this, data->size());
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    auto p1 = lhs.wp.lock(), p2 = rhs.wp.lock();
    if (p1 == p2) // vector<T>的地址相等
    {
        return (lhs.curr < rhs.curr); // 位置也小于或者两个都是空的，就认为指针小于
    }
    std::cerr << RED << "Compare two pointers pointed to different Blob!"
              << WHITE << '\n';
    return false;
}

template <typename T>
T &BlobPtr<T>::operator[](size_t i)
{
    auto p = check(curr + i + 1, "index past end");
    return (*p)[curr + i];
}

template <typename T>
const T &BlobPtr<T>::operator[](size_t i) const
{
    auto p = check(curr + i + 1, "index past end");
    return (*p)[curr + i];
}

#endif