#include "Message_ex49.h"
#include "StrVec_ex49.h"
#include <vector>

using std::vector;

int main()
{
    Message m1, m2;
    m1 = std::move(m2);
    cout << "=\n";
    StrVec sv1;
    StrVec sv2 = std::move(sv1);
    vector<Message> vms;
    cout << "=\n";
    vms.push_back(m1);
    cout << "=\n";
    vms.push_back(m1);
    cout << "=\n";
    vms.push_back(m1);
    cout << "=\n";
    return 0;
}