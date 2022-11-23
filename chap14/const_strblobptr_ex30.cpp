#include "ConstStrBlobPtr_chap14.h"
#include <iostream>

using std::cout;

int main()
{
    const StrBlob sb{"I", "love", "You"};
    auto p = sb.begin();
    cout << *(p.incr().incr()) << '\n';
    return 0;
}