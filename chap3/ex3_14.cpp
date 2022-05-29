#include <iostream>
#include <vector>

using std::cin;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    int tmp = 0;
    vector<int> ivec;
    while (cin >> tmp)
        ivec.push_back(tmp);
    return 0;
}