#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::cin;

int main()
{
    vector<int> ivec;
    int i;
    while (cin >> i)
        ivec.push_back(i);
    for (vector<int>::size_type idx=0;
     idx<ivec.size()-1;++idx)
        cout << ivec[idx] + ivec[idx+1] << ' ';
    cout << endl;
    return 0;
}