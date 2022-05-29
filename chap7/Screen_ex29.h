#ifndef SCREEN_EX23_H
#define SCREEN_EX23_H

#include <string>
#include <iostream>

using std::ostream;
using std::string;

class Screen
{
public:
    using pos = string::size_type;

private:
    pos height = 0, width = 0;
    pos cursor = 0;
    string contents;
    void do_display(ostream &os) const { os << contents; }

public: // move get constructors
    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' '){};
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c){};
    Screen move(pos, pos);
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const
    {
        pos row = r * width;
        return contents[row + c];
    }
    const Screen display(ostream &os) const
    {
        do_display(os);
        return *this;
    }
    Screen display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    Screen set(char ch)
    {
        contents[cursor] = ch;
        return *this;
    }
    Screen set(pos r, pos c, char ch)
    {
        contents[r * width + c] = ch;
        return *this;
    }
};

Screen Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

#endif