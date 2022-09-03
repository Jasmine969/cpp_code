#ifndef STRBLOBPTR_EX19_H
#define STRBLOBPTR_EX19_H

#include <vector>
#include <memory>
#include <string>
#include <initializer_list>
#include <stdexcept>

using std::initializer_list;
using std::make_shared;
using std::out_of_range;
using std::runtime_error;
using std::shared_ptr;
using std::string;
using std::vector;
using std::weak_ptr;

class StrBlobPtr;
class StrBlob
{
public:
    friend class StrBlobPtr;
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()){};
    StrBlob(initializer_list<string> i1) : data(make_shared<vector<string>>(i1)){};
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    string &front();
    string &back();
    string &front() const;
    string &back() const;
    void push_back(string s) { data->push_back(s); }
    void pop_back();
    StrBlobPtr begin();
    StrBlobPtr end();

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

class StrBlobPtr
{
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
private:
    typedef StrBlob::size_type size_type;
    size_type curr;
    weak_ptr<vector<string>> wp;
    shared_ptr<vector<string>> check(size_type, const string &msg) const;

public:
    StrBlobPtr() : curr(0){};
    StrBlobPtr(StrBlob &sb, size_type i = 0) : wp(sb.data), curr(i){};
    string &deref() const;    // 解引用
    StrBlobPtr &incr(); // 前缀递增
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

inline bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    auto p1 = lhs.wp.lock(), p2 = rhs.wp.lock();
    if (p1 == p2) // vector<string>的地址相等
    {
        return (lhs.curr == rhs.curr) || !p1; // 位置也相等或者两个都是空的，就认为指针相等
    }
    return false;
}

inline bool neq(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return !eq(lhs, rhs);
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}
#endif