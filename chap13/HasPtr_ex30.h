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
    HasPtr(int i_, const string &s = "") : ps(new string(s)), i(i_) {}
    HasPtr(const HasPtr &hp) : ps(new string(*hp.ps)), i(hp.i) {}
    HasPtr &operator=(const HasPtr &hp)
    {
        auto newp = new string(*hp.ps);
        delete ps;
        ps = newp;
        i = hp.i;
        return *this;
    }
    ~HasPtr() { delete ps; }
    const string &get_str() const { return *ps; }
    void set_str(const string &s) { *ps = s; }

private:
    string *ps;
    int i;
};

void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "run swap\n";
}

#endif