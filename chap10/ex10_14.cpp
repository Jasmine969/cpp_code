#include <iostream>

using std::cout;

int main()
{
    // cout << ([] (int a, int b) {return a + b;})(1,5) << '\n';
    auto lambda_sum = [] (int a, int b) {return a + b;};
    cout << lambda_sum(1,5) << '\n';
    return 0;
}