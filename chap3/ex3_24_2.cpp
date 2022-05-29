#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int i = 0;
    vector<int> ivec;
    while (cin >> i)
        ivec.push_back(i);
    auto len = ivec.size();
    auto tail = ivec.cend();
    for (auto it = ivec.cbegin();
         it < ivec.cbegin() + len / 2; ++it)
    {
        --tail;
        cout << *it + *tail << ' ';
    }
    if (len % 2)
        cout << ivec[len / 2];
    cout << endl;
    return 0;
}