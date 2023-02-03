#ifndef CHAPTER6_H
#define CHAPTER6_H

#include <string>
#include <vector>
using std::string;
using std::vector;

template <typename> 
double absl(double);
template double absl<char>(double x);
// int fact(int n);
void defaultArgu(int i, int j = 2, char c = 'p');
void defaultArgu(int i = 1, int j, char c);

inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

extern vector<int (*)(int, int)> fvec;

#endif