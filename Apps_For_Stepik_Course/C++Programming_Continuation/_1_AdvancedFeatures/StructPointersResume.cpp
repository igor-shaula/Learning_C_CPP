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
    Unit u = {1, 2};
    Unit *p = &u;
    // invocation is a bit strange in syntax:
    cout << ((u.*method)() == (p->*method)()) << endl;
    cout << (u.*field == p->*field) << endl; // less brackets with fields
}

int main() {
    showPointersUsage();
    return 0;
}

// C++11: можно не использовать все эти танцы со скобочками и звёздочками и просто использовать auto
// По стандарту ".*" - это один оператор. И "->*" - это тоже один оператор.

// what is inside pointer to function - address of this function

// what is inside pointer to field of a class - shift from the very beginning of the object

// what is inside pointer to method - address of the method in segment of code (for non-virtual),
// also as there are common and virtual methods - instead of method's address we need its number in
// virtual method table, also we need shift from base class pointer to derived/this class pointer \\