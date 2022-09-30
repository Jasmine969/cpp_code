#ifndef NUMBERED_EX16_NO_COPY_H
#define NUMBERED_EX16_NO_COPY_H

#include <iostream>
using std::cout;

class numbered
{
    friend void f(const numbered &s);

private:
    unsigned mysn;
    static int sn;

public:
    numbered() : mysn(sn++) {}
    // numbered(const numbered& s1): mysn(sn++) {}
};

int numbered::sn = 0;

void f(const numbered &s) { cout << s.mysn << '\n'; }
#endif