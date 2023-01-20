#include <iostream>

using std::cout;

template <typename T, unsigned N>
T *begin(T (&arr)[N])
{
    return arr;
}

template <typename T, unsigned N>
T *end(T (&arr)[N])
{
    return arr + N;
}

int main()
{
    double a[]{1.1, 2, 3.4, 6.3};
    for (auto it = begin(a); it != end(a); ++it)
    {
        cout << *it << ' ';
    }
    cout << '\n';
    return 0;
}