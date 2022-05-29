#ifndef CHAPTER6_H
#define CHAPTER6_H

#include <string>
#include <vector>
using std::string;
using std::vector;

double absl(double x);
// int fact(int n);
void defaultArgu(int i, int j = 2, char c = 'p');
void defaultArgu(int i = 1, int j, char);

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
    // return 1 < 2;
}

extern vector<int (*)(int, int)> fvec;

#endif