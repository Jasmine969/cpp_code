#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::getline;

int main()
{
    vector<string> text;
    string w;
    while (getline(cin, w))
        text.push_back(w);
    for (auto word = text.begin(); word != text.end(); ++word)
        {
            if (*word == "")
                cout << "empty" << endl;
            else
                cout << *word << endl;
        }
    
    return 0;
}