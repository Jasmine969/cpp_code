#include <iostream>
// #include "Chapter6.h"

using std::endl;
using std::cout;

int j_val = 1;
char c_val = 'p';
void defaultArgu(int i, int j = j_val, char c = c_val)
{
    cout << i << ' ' << j << ' ' << c;
}

// int main()
// {
//     int j_val = 10;
//     cout << j_val << endl;
//     {
//         int k = 0;
//         j_val = 100;
//         cout << j_val << endl;
//     }
//     cout << j_val << endl;
//     // c_val = 'j';
//     // defaultArgu(2);
//     return 0;
// }