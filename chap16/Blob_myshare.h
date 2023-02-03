#ifndef BLOB_MYSHARE_H
#define BLOB_MYSHARE_H

#include <vector>
using std::vector;

#include "sharedPtr.h"

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
class Blob;
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator<(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob
{
    friend bool operator==<T>(const Blob<T> &lhs, const Blob<T> &rhs);
    friend bool operator< <T>(const Blob<T> &lhs, const Blob<T> &rhs);

public:
    typedef typename vector<T>::size_type size_type;
    Blob() : data(new vector<T>()){};
    Blob(initializer_list<T> i1) : data(new vector<T>(i1)){};
    template <typename It>
    Blob(It b, It e) : data(new vector<T>(b, e)) {}
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
    T &operator[](size_t);
    const T &operator[](size_t) const;

private:
    sharedPtr<vector<T>> data;
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

#endif