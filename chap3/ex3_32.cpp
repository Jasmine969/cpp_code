#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec;
    for (int i=0; i < 10;++i)
        ivec.push_back(i); // push_back更快一点
    for (auto i:ivec)
        cout << i << ' ';
    cout << endl;

    vector<int> jvec = ivec;
    for (auto j:jvec)
        cout << j << ' ';
    cout << endl;

    return 0;
}