#include <iostream>

using std::cout;
using std::endl;

int &get(int *arry, int index)
{
    return arry[index];
    // return *(arry + index);
}

int main()
{
    int ia[10];
    for (auto n : ia)
        cout << n << ' ';
    cout << endl;
    for (int i = 0; i!=10; ++i)
    {
        get(ia, i) = i;
    }
    for (auto n : ia)
        cout << n << ' ';
    cout << endl;
    return 0;
}