#ifndef CONSTSTRBLOBPTR_EX22_H
#define CONSTSTRBLOBPTR_EX22_H

#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <stdexcept>
// #include "StrBlobPtr_ex19.h"

using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::runtime_error;
using std::shared_ptr;
using std::string;
using std::vector;
using std::weak_ptr;

class ConstStrBlobPtr;
class StrBlob
{
public:
    friend class ConstStrBlobPtr;
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()){}
    StrBlob(initializer_list<string> i1) : data(make_shared<vector<string>>(i1)){}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    string &front();
    string &back();
    string &front() const;
    string &back() const;
    void push_back(string s) { data->push_back(s); }
    void pop_back();
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

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

class ConstStrBlobPtr
{
private:
    typedef StrBlob::size_type size_type;
    size_type curr;
    weak_ptr<vector<string>> wp;
    shared_ptr<vector<string>> check(size_type, const string &msg);

public:
    ConstStrBlobPtr() : curr(0){};
    ConstStrBlobPtr(const StrBlob &sb, size_type i = 0) : wp(sb.data), curr(i){};
    string &deref();    // 解引用
    ConstStrBlobPtr &incr(); // 前缀递增
};

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_type i, const string &msg)
{
    // 先检查vector是否存在
    auto p = wp.lock();
    if (!p)
        throw runtime_error("Unbounded ConstBlobPtr");
    // 再检查下标是否越界
    if (i >= p->size())
        throw out_of_range(msg);
    return p;
}

string &ConstStrBlobPtr::deref()
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
    check(curr, "increment past end");
    ++curr;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
    return ConstStrBlobPtr(*this, data->size());
}

#endif