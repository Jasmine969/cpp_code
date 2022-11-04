#include "StrVec_ex49_2.h"
#include <iostream>
#include <string>
#include <utility>
#include <memory>
#include <vector>

using std::cout;
using std::string;
using std::allocator;
using std::vector;

int main()
{
    StrVec sv;
    cout << sv.size() << "\t" << sv.capacity() << '\n';
    sv.push_back("abc");
    cout << sv.size() << "\t" << sv.capacity() << '\n';
    sv.push_back("abc");
    cout << sv.size() << "\t" << sv.capacity() << '\n';
    sv.push_back("abc");
    cout << sv.size() << "\t" << sv.capacity() << '\n';
    sv.push_back("abc");
    cout << sv.size() << "\t" << sv.capacity() << '\n';
    sv.push_back("abc");
    cout << sv.size() << "\t" << sv.capacity() << '\n';
    sv.push_back("abc");
    cout << sv.size() << "\t" << sv.capacity() << '\n';
    sv.push_back("abc");
    cout << sv.size() << "\t" << sv.capacity() << '\n';
    sv.push_back("abc");
    cout << sv.size() << "\t" << sv.capacity() << '\n';
    sv.push_back("abc");
    cout << sv.size() << "\t" << sv.capacity() << '\n';
    return 0;
}