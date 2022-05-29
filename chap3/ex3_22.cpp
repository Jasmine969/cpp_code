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
    // vector<string> text{
    //     "If", " ", "I", " ", "showed", " ",
    //     "you", " ", "my", " ", "flaws,", "",
    //     " ", "if", " "};
    vector<string> text;
    string w;
    while (getline(cin, w))
        text.push_back(w);
    for (auto word = text.begin(); word != text.end() &&
     !word -> empty(); ++word)
        {
            for (auto &c : *word)
                c = toupper(c);
            cout << *word;
        }
    
    return 0;
}