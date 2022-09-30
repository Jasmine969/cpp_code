#include <string>

using std::string;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr &operator=(const HasPtr &hp1)
    {
        delete ps;
        ps = new string(*hp1.ps);
        i = hp1.i;
        return *this;
    }

private:

    string *ps;
    int i;
};
