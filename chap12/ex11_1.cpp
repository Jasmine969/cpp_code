#include <iostream>
#include "StrBlob.h"

using std::cout;

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b1.size() << '\t' << b2.size() << '\n';
    }
    cout << b1.size() << '\n';
    return 0;
}
