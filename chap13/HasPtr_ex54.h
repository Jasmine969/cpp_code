#ifndef HASPTR_EX30_H
#define HASPTR_EX30_H

#include <string>
#include <iostream>

using std::cout;
using std::string;

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const char *cp = "") : ps(new string(cp)), i(0) {}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i)
    {
        cout << "copy constructor\n";
    }
    HasPtr &operator=(HasPtr rhs)
    {
        swap(*this, rhs);
        cout << "copy and swap\n";
        return *this;
    }
    ~HasPtr() { delete ps; }
    HasPtr &operator=(HasPtr &&) noexcept;
    const string &get_str() const { return *ps; }
    void set_str(const string &s) { *ps = s; }
    bool operator<(const HasPtr &) const;

private:
    string *ps;
    int i;
};

HasPtr &HasPtr::operator=(HasPtr &&rhs) noexcept
{
    if (this != &rhs)
    {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }
    cout << "move-assigment\n";
    return *this;
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *ps < *rhs.ps;
}

#endif