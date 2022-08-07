#include <map>
#include <iostream>
#include <string>

using std::cout;
using std::multimap;
using std::string;

int main()
{
    multimap<string, string> books{
        {"Lu Xun", "From Baicaoyuan To Sanweishuwu"},
        {"Lu Xun", "She Xi"},
        {"Lu Xun", "Mr. Tengye"},
        {"Wu Jun", "Beauty of Mathematics in Computer Science"},
        {"Frank White", "Fluid Dynamics"},
        {"Wu Jun", "At the peak of the wake"}};
    string authorDrop = "Wu";
    auto cnt = books.count(authorDrop);
    if (cnt == 0)
    {
        cout << authorDrop << " is not found in books!\n\n";
    }
    else
    {
        auto it = books.find(authorDrop);
        auto cur_cnt = cnt;
        while (cur_cnt)
        {
            it = books.erase(it);
            --cur_cnt;
        }
        cout << "Totally " << cnt << " has been erased.\n\n";
    }

    for (auto p : books)
    {
        cout << p.first << "\t" << p.second << "\n";
    }
    return 0;
}