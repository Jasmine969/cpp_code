#ifndef NUMBERED_EX14_H
#define NUMBERED_EX14_H

#include <iostream>
using std::cout;

class numbered
{
    friend void f(numbered s);

private:
    unsigned mysn;
    static int sn;

public:
    numbered() : mysn(sn++) {}
};

int numbered::sn = 0;

void f(numbered s) { cout << s.mysn << '\n'; }
#endif