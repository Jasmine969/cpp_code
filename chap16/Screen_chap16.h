#ifndef SCREEN_CHAP16_H
#define SCREEN_CHAP16_H

#include <string>
using std::string;

#include <iostream>
using std::istream;
using std::ostream;

// forward declaration
template <size_t, size_t>
class Screen;
template <size_t height, size_t width>
ostream &operator<<(ostream &, const Screen<height, width> &);
template <size_t height, size_t width>
istream &operator>>(istream &, Screen<height, width> &);

template <size_t height, size_t width>
class Screen
{
    friend ostream &operator<< <height, width>(ostream &, const Screen<height, width> &);
    friend istream &operator>> <height, width>(istream &, Screen<height, width> &);

public:
    using pos = string::size_type;

private:
    pos cursor = 0;
    string contents;
    void do_display(ostream &os) const { os << contents; }

public:
    Screen(char c = ' ') : contents(height * width, c){};
    Screen &move(pos, pos);
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const
    {
        pos row = r * width;
        return contents[row + c];
    }
    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }
    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }
    Screen &set(char ch)
    {
        contents[cursor] = ch;
        return *this;
    }
    Screen &set(pos r, pos c, char ch)
    {
        contents[r * width + c] = ch;
        return *this;
    }
};

template <size_t height, size_t width>
Screen<height, width> &Screen<height, width>::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

template <size_t height, size_t width>
ostream &operator<<(ostream &os, const Screen<height, width> &scr)
{
    return os << scr.contents;
}

template <size_t height, size_t width>
istream &operator>>(istream &is, Screen<height, width> &scr)
{
    char c;
    is >> c;
    scr.set(c);
    return is;
}
#endif