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
    for (auto it = ivec.cbegin(); it < ivec.cend() - 1; ++it)
        cout << *it + *(++it) << ' ';
    if (ivec.size() % 2)
        cout << ivec[ivec.size()-1];
    cout << endl;
    return 0;
}