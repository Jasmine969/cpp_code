#include <iostream>

using std::cout;

template <typename T, size_t N>
constexpr size_t sizeArr(const T (&arr)[N])
{
    return N;
    // size_t r = sizeof(arr) / sizeof(arr[0]);
    // if (r > 7)
    //     return r;
    // return r + 1;
}

int main()
{
    double a[] = {1, 2, 3, 4, 556, 1};
    constexpr size_t ret = sizeArr(a);
    cout << ret << '\n';
    return 0;
}