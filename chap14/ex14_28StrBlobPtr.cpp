#include <iostream>
#include "StrBlobPtr_chap14.h"

using std::cout;

int main()
{
    StrBlob sb{"I", "Love", "You"};
    auto p = sb.begin();
    cout << (p++).deref() << '\n'; 
    // cout << (p--).deref() << '\n';
    cout << p.deref() << '\n';
    cout << sb.begin()[1] << '\n';
    return 0;
}