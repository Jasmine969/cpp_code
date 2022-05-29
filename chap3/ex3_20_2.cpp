#include <iostream>
#include <vector>
#include <cmath>

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
    auto len = ivec.size();
    double mid = ceil(double(len) / 2);
    for (decltype(len) ind=0; ind<mid;++ind)
        cout << ivec[ind] + ivec[len-ind-1] << ' ';
    cout << endl;
    return 0;
}