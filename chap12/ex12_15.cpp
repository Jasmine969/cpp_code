#include <memory>

using std::shared_ptr;

struct destination;
struct connection{};
connection connect(destination*);
void disconnect(connection);


void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> c1(&c,
    [] (connection* p) {disconnect(*p);} );
}