#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <string>
#include <cstring>

template <typename T>
unsigned occur(vector<T> &vec, const T &v)
{
    unsigned cnt = 0;
    for (auto i : vec)
    {
        if (i == v)
            ++cnt;
    }
    return cnt;
}

template <>
unsigned occur(vector<const char*> &vec, const char* const &v)
{
    unsigned cnt = 0;
    for (auto i : vec)
    {
        if (!std::strcmp(i, v))
            ++cnt;
    }
    return cnt;
}

int main()
{
    vector<int> vint{1, 2, 3, 4, 2, 1, 4, 4};
    cout << occur(vint, 4) << '\n';
    vector<double> vdb{1.1, 2.2, -1.1, -2.2, -1, -1, -1};
    cout << occur(vdb, -1.) << '\n';
    vector<std::string> vstr{"I", "love", "you", "you"};
    cout << occur(vstr, std::string("you")) << '\n';
    const char* cp= "you";
    vector<const char*> vc{"I","love","you", "you"};
    cout << occur(vc, cp) << '\n';
    return 0;
}