#include "StrBlobPtr_chap14.h"
#include <iostream>

using std::cout;

int main()
{
    StrBlob sv{"I", "Love", "China"};
    cout << sv[0] << '\n';
    auto it = sv.begin();
    cout << it[2] << '\n';
    return 0;
}