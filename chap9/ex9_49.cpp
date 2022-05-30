#include <iostream>
#include <string>
#include <fstream>

using std::ifstream;
using std::string;
using std::cout;

int main()
{
    ifstream inp("words.txt");
    string word, best_word;
    unsigned max_len = 0;
    while (inp >> word)
    {
        if (word.find_first_of("bdfhklgjpqy")) // 确认无出头单词
        {
            continue;
        }
        if (ispunct(word[word.size() - 1])) // 删除标点符号
        {
            word.erase(word.end() - 1);
        }
        if (word.size() > max_len)
        {
            max_len = word.size();
            best_word = word;
        }
    }
    cout << "best word:" << "\t" << best_word << "\tmax length:\t" << max_len << "\n";
    return 0;
}