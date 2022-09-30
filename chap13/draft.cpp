#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <memory>
#include "StrBlob_ex26.h"

using std::shared_ptr;
using std::cout;
using std::ostringstream;
using std::string;
using std::setfill;
using std::setw;
using std::make_shared;
using std::swap;

class HasPtr
{
public:
    HasPtr(int i_, const string &s = ""): ps(new string(s)), i(i_) {}
    HasPtr(const HasPtr& hp): ps(new string (*hp.ps)), i(hp.i) {}
    HasPtr& operator=(const HasPtr& hp)
    {
        auto newp = new string(*hp.ps);
        delete ps;
        ps = newp;
        i = hp.i;
        return *this;
    }
    ~HasPtr() {delete ps;}
private:
    string *ps;
    int i;
};

int main()
{
    vector<int> v1{1,2,3,4};
    vector<int> v2{2,4};
    // swap(v1, v2);
    vector<int> temp = v1;
    v1 = v2;
    v2 = temp;
    cout << v1.size() << '\t' << v2.size() << '\n';
    return 0;
}//
