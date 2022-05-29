#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<string> svec;
    svec.reserve(1024);
    for (unsigned i = 0; i != 1000; ++i)
    {
        svec.push_back("he");
    }
    cout << "size: " << svec.size() << " capacity:"
         << svec.capacity() << '\n';
    svec.resize(svec.size() + svec.size() / 2);
    cout << "size: " << svec.size() << " capacity:"
         << svec.capacity() << '\n';
    return 0;
}