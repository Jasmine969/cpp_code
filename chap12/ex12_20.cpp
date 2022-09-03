#include "StrBlobPtr_ex19.h"
#include <fstream>
#include <iostream>

using std::ifstream;
using std::getline;
using std::cout;

int main()
{
    ifstream in("lyrics2.txt");
    StrBlob sb;
    string line;
    while (getline(in, line))
    {
        sb.push_back(line);
    }
    auto it = sb.begin();
    for (unsigned i = 0; i != sb.size(); ++i)
    {
        cout << it.deref() << "\n";
        it.incr();
    }
    return 0;
}