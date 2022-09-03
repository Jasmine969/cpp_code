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
    
    for (auto it = sb.begin(); neq(it, sb.end()); it.incr())
    {
        cout << it.deref() << "\n";
    }
    return 0;
}