#include <iostream>
#include <string>
#include <cstddef>

using std::cout;
using std::endl;
using std::size_t;
using std::string;

int main(int argc, char *argv[])
{
    for (size_t i = 0; i < argc; ++i)
    {
        cout << "Argument" << i << ": " << argv[i] << endl;
    }
    return 0;
}