#include <iostream>
#include <string>
#include <cstddef>

using std::cout;
using std::endl;
using std::size_t;
using std::string;

int main(int argc, char *argv[])
{
    string s;
    for (size_t i = 0; i < argc; ++i)
    {
        s += argv[i];
        s += '\n';
    }
    cout << s << endl;
    return 0;
}