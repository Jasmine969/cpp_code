#include <string>
#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <queue>

using std::cout;
using std::deque;
using std::priority_queue;
using std::queue;
using std::stack;
using std::stoi;
using std::string;
using std::vector;

int main()
{
    vector<int> intVec{1, 2, 3, 4};
    deque<int> intDeq{1, 2, 3, 4};
    stack<int, vector<int>> intStack(intVec);
    queue<int> intQue(intDeq);
    priority_queue<int> intPrq;
    string s("-12:13");
    string::size_type p;
    cout << stoi(s, &p);
    cout << ' ' << p << '\n';
    return 0;
}