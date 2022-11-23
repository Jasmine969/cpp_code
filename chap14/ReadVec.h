#ifndef READVEC
#define READVEC

#include <iostream>
#include <string>

using std::cin;
using std::getline;
using std::istream;
using std::string;

class ReadString
{
public:
    ReadString(istream &i = cin) : is(i) {}
    string operator()()
    {
        string s;
        if (getline(is, s))
        {
            return s;
        }
        return "";
    }

private:
    istream &is;
};

#endif