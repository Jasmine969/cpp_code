#include "StrBlobPtr_chap14.h"

int main()
{
    StrBlob sb1{"I", "Love", "yOU"};
    StrBlob sb2{"I", "Love", "yOU"};
    auto p1 = sb1.begin();
    auto p2 = sb1.end();
    cout << std::boolalpha << (sb1 == sb2) << '\n';
    cout << (p1 == p2) << '\n';
    return 0;
}