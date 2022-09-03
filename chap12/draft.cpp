#include <memory>
#include <iostream>
#include <vector>

using std::cout;
using std::make_shared;
using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::weak_ptr;

struct connection {};
struct destination;
void end_connection(connection*);
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
int (*arrPtr(int i))[5]
{
    return (i%2)? &odd : &even;
}

int main()
{
    const char* cp = "hello";
    cout << cp[3] << '\n';

    return 0;
}