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
        if (!isupper(word[0]))
            continue;
        if (word == preword)
        {
            break;
        }
        preword = word;
    }
    if (cin)
    {
        cout << "The repeated word with an uppercase initial is " << word << '.' << endl;
    }
    else
        cout << "No repeated word." << endl;
    return 0;
}