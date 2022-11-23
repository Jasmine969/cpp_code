#include "StrBlobPtrPtr.h"
#include <iostream>

using std::cout;

int main()
{
    StrBlob sb{"I", "lOVE", "You"};
    auto sbp = sb.begin() + 1;
    cout << *sbp << '\n';
    StrBlobPtrPtr sbpp(sbp);
    cout << sbpp->size() << '\n';
    return 0;
}
