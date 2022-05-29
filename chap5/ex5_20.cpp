#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string preword, word;
    while (cin >> word)
    {
        if (word == preword)
        {
            break;
        }
        preword = word;
    }
    if (cin)
    {
        cout << "The repeated word is " << word << '.' << endl;
    }
    else
        cout << "No repeated word." << endl;
    return 0;
}