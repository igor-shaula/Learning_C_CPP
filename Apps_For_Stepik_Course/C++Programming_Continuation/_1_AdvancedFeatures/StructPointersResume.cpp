#include <iostream>
using namespace std;

// sample of using pointers to methods and pointers to fields alongside each other

struct Unit {
    unsigned id() const { return id_; }
    unsigned int id_;
    unsigned hp;
};

void showPointersUsage() {
    unsigned (Unit::*method)() const = &Unit::id; // note that method id is without () here
    unsigned Unit::*field = &Unit::hp; // we're taking address - because we need a pointer
    // now 'method' is a pointer to a Unit's method and 'field' is a pointer to a Unit's field
    Unit u;
    Unit *p = &u;
    // invocation is a bit strange in syntax:
    cout << ((u.*method)() == (p->*method)()) << endl;
    cout << (u.*field == p->*field) << endl; // less brackets with fields
}

int main() {
    showPointersUsage();
    return 0;
}