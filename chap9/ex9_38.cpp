#include <vector>
#include <string>
#include <iostream>
#include "../myfunc.h"

using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<int> vi;
    cout << "size: " << vi.size() << " capacity:"
         << vi.capacity() << '\n';
    for (unsigned i = 0; i != 10; ++i)
    {
        vi.push_back(i);
        printVec(vi);
        cout << "size: " << vi.size() << " capacity:"
             << vi.capacity() << '\n';
    }
    vi.reserve(50);
    for (unsigned i = 0; i != 60; ++i)
    {
        vi.push_back(i);
        printVec(vi);
        cout << "size: " << vi.size() << " capacity:"
             << vi.capacity() << '\n';
    }
    vi.resize(30);
    cout << "size: " << vi.size() << " capacity:"
         << vi.capacity() << '\n';
    return 0;
}