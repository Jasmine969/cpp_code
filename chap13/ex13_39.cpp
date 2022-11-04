#include <string>
#include <iostream>
#include "StrBlob_ex26.h"
#include "StrVec_ex42.h"

using std::cout;
using std::string;

int main()
{
    StrVec sv1{"A A"};
    sv1.push_back("hello");
    sv1.push_back(" world");
    sv1.push_back(" !");
    sv1.push_back("hello");
    sv1.push_back(" world");
    cout << sv1.size() << '\t' << sv1.capacity() << '\n';
    
    for (auto beg = sv1.begin(); beg != sv1.end(); ++beg)
    {
        cout << *beg << ' ';
    }
    cout << '\n';
    sv1.resize(60, "ggg");
    cout << sv1.size() << '\t' << sv1.capacity() << '\n';
    cout << sv1[58] << '\n';
    cout << string(10, '=') << '\n';
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    cout << v.size() << " " << v.capacity() << '\n';
    v.resize(60, 10);
    cout << v.size() << " " << v.capacity() << '\n';
    cout << v[58] << '\n';
    return 0;
}
