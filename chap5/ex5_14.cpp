#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string word;
    vector<string> vecWord(1);
    vector<int> vecCnt{1};
    cin >> vecWord[0];
    unsigned int ind = 0;
    unsigned int maxInd = 0;
    while (cin >> word)
    {
        if (word == vecWord[ind])
        {
            ++vecCnt[ind];
        }
        else
        {
            vecWord.push_back(word);
            vecCnt.push_back(1);
            if (vecCnt[maxInd] < vecCnt[ind])
            {
                maxInd = ind;
            }
            ++ind;
        }
    }
    cout << "The word \"" << vecWord[maxInd] << "\" appears " << vecCnt[maxInd] << " times." << endl;
    return 0;
}