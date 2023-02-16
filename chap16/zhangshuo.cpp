#include <iostream>

using namespace std;

template <typename T>
T maxn(T *ar, int n)
{
    T a = ar[0];
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > a)
        {
            a = ar[i];
        }
    }
    return a;
}
template <>
char *maxn<char *>(char **ar, int size)
{
    char *max = ar[0];
    int ezis = sizeof(ar[0]);
    for (int i = 0; i < size; i++)
    {
        if (sizeof(ar[i]) > ezis)
        {
            ezis = sizeof(ar[i]);
            max = ar[i];
        }
    }
    return max;
}

// char *maxn(char *ar[], int size)
// {
//     char *max = ar[0];
//     int ezis = sizeof(ar[0]);
//     for (int i = 0; i < size; i++)
//     {
//         if (sizeof(ar[i]) > ezis)
//         {
//             ezis = sizeof(ar[i]);
//             max = ar[i];
//         }
//     }
//     return max;
// }

int main()
{
    char *ch[5] =
        {
            "ab",
            "abc",
            "abcd",
            "abcde",
            "abcdef"};
    // char *mmax = maxn<char *>(ch, 5);
    int i[] = {1,2,3};
    cout << sizeof(&i[0]) << '\n';
    cout << sizeof(&ch[0]) << '\t' << sizeof(ch[4]) << '\n';
    // char *mmax = maxn(ch, 5);
    // cout << mmax << endl;
    return 0;
}