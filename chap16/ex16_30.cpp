#include "Blob_myshare.h"
#include <iostream>
using std::cout;

int main()
{
    Blob<int> bi{1,2,3};
    bi.push_back(12);
    bi.push_back(13);
    for (size_t i = 0; i != bi.size(); ++i)
    {
        cout << bi[i] << '\t';
    }
    cout << '\n';
    cout << bi.front() << '\n';
    return 0;
}