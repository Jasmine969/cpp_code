#include <iostream>

using std::cout;

template <typename T, unsigned N>
void print(const T (&arr)[N])
{
    for (auto i : arr)
        cout << i << '|';
    cout << '\n';
}

int main()
{
    int a[5]{1,3,5,7,8};
    print(a);
    char b[] = "hello";
    print(b);
    return 0;
}