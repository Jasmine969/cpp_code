#include "ConstStrBlobPtr_ex22 copy.h"
#include <iostream>

using std::ifstream;
using std::getline;
using std::cout;

int main()
{
    const StrBlob sb({"I", "LOVE", "you"});
    auto it = sb.begin();
    for (unsigned i = 0; i != sb.size(); ++i)
    {
        cout << it.deref() << "\n";
        it.incr();
    }
    return 0;
}