#include <iostream>

using std::cout;

int main()
{
    int i = -2;
    auto lambda_sum = [i] (int a) {return a + i;};
    cout << lambda_sum(1) << '\n';
    return 0;
}