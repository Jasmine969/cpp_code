#include <memory>

using std::shared_ptr;

struct destination;
struct connection{};
connection connect(destination*);
void disconnect(connection);

void end_connection(connection* c)
{
    disconnect(*c);
}

void f(destination &d)
{
    connection c = connect(&d);
    shared_ptr<connection> c1(&c, end_connection);
}