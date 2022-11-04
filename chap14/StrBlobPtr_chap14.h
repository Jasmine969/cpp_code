#ifndef STRBLOBPTR_CHAP14_H
#define STRBLOBPTR_CHAP14_H

#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <iostream>

using std::cout;
using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::runtime_error;
using std::shared_ptr;
using std::string;
using std::vector;
using std::weak_ptr;

const string RED = "\033[0;41;37m";
const string WHITE = "\033[0;40;37m";

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);

public:
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()){};
    StrBlob(vector<string> *p) : data(p){};
    StrBlob(initializer_list<string> i1) : data(make_shared<vector<string>>(i1)){};
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    string &front();
    string &back();
    string &front() const;
    string &back() const;
    void push_back(const string &s)
    {
        data->push_back(s);
        cout << "copy push\n";
    }
    void push_back(string &&s)
    {
        data->push_back(std::move(s));
        cout << "move push\n";
    }
    void pop_back();
    StrBlobPtr begin();
    StrBlobPtr end();
    string &operator[](size_t);
    const string &operator[](size_t) const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type, const string &) const;
};

void StrBlob::check(size_type i, const string &msg) const
{
    if (data->size() <= i)
    {
        throw out_of_range(msg);
    }
}

string &StrBlob::front()
{
    check(0, "front on an empty StrBlob.");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on an empty StrBlob.");
    return data->back();
}

string &StrBlob::front() const
{
    check(0, "front on an empty StrBlob.");
    return data->front();
}

string &StrBlob::back() const
{
    check(0, "back on an empty StrBlob.");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on an empty StrBlob.");
    data->pop_back();
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}

string &StrBlob::operator[](size_t i)
{
    return (*data)[i];
}

const string &StrBlob::operator[](size_t i) const
{
    return (*data)[i];
}

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);

private:
    typedef StrBlob::size_type size_type;
    size_type curr;
    weak_ptr<vector<string>> wp;
    shared_ptr<vector<string>> check(size_type, const string &msg) const;

public:
    StrBlobPtr() : curr(0){};
    StrBlobPtr(StrBlob &sb, size_type i = 0) : wp(sb.data), curr(i){};
    string &deref() const; // 解引用
    StrBlobPtr &incr();    // 前缀递增
    string &operator[](size_t);
    const string &operator[](size_t) const;
};

shared_ptr<vector<string>>
StrBlobPtr::check(size_type i, const string &msg) const
{
    // 先检查vector是否存在
    auto p = wp.lock();
    if (!p)
        throw runtime_error("Unbounded StrBlobPtr");
    // 再检查下标是否越界
    if (i >= p->size())
        throw out_of_range(msg);
    return p;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end");
    ++curr;
    return *this;
}

inline bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto p1 = lhs.wp.lock(), p2 = rhs.wp.lock();
    if (p1 == p2) // vector<string>的地址相等
    {
        return (lhs.curr == rhs.curr) || !p1; // 位置也相等或者两个都是空的，就认为指针相等
    }
    return false;
}

inline bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto p1 = lhs.wp.lock(), p2 = rhs.wp.lock();
    if (p1 == p2) // vector<string>的地址相等
    {
        return (lhs.curr < rhs.curr); // 位置也小于或者两个都是空的，就认为指针小于
    }
    std::cerr << RED << "Compare two pointers pointed to different StrBlob!"
              << WHITE << '\n';
    return false;
}

string &StrBlobPtr::operator[](size_t i)
{
    auto p = check(curr + i, "dereference past end");
    return (*p)[curr + i];
}

const string &StrBlobPtr::operator[](size_t i) const
{
    auto p = check(curr + i, "dereference past end");
    return (*p)[curr + i];
}

#endif