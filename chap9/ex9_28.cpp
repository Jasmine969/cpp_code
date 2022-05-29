#include <forward_list>
#include <iostream>
#include <string>

using std::cout;
using std::forward_list;
using std::string;

void fwdListInsert(forward_list<string> &lst, const string &s_pos, const string &s_insert)
{
    auto prev = lst.cbefore_begin(), curr = lst.cbegin();
    bool exist = false;
    while (curr != lst.cend())
    {
        if (*curr == s_pos)
        {
            curr = lst.insert_after(curr, s_insert);
            exist = true;
            // ++prev; // 这行可以不用，因为只有在exist=false的时候才需要用prev
        }
        ++prev;
        ++curr;
    }
    if (!exist)
    {
        lst.insert_after(prev, s_insert);
    }
}

int main()
{
    forward_list<string> lstr{"I", "If", "I", "got", "I", "locked", "away"};
    fwdListInsert(lstr, "I", "love");
    for (auto s : lstr)
    {
        cout << s << ' ';
    }
    cout << '\n';
    return 0;
}