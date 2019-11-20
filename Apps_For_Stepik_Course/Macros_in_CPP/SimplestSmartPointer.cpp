#include "SimplestSmartPointer.hpp"

void checkPlainPointer();

void checkSimplestSmartPointer();

int main() {
    checkPlainPointer();
    checkSimplestSmartPointer();
    return 0;
}

void checkPlainPointer() {
    /* 1 - created with assignment operator */
    int value = 5;
    cout << "value=" << value << endl;
    int *a = new int(1);
//    int *a = &value; // we have to allocate memory with 'new' before using 'delete'
    cout << "*a=" << *a << endl;
    int *b = a;
//    int *b = a; // we have to allocate memory with 'new' before using 'delete'
    cout << "*b=" << *b << endl;
    delete b; // clearing the memory for the first time
    cout << "b=" << b << endl;
    delete a; // clearing the memory for the SECOND time - because we've passed its value to 'b' before
    cout << "a=" << a << endl;
    delete a; // clearing our memory AGAIN with the same pointer which is already dead
    cout << "*a=" << *a << endl;

    /* 2 - created with 'new' operator */
    int *p = new int(9);
    cout << "*p=" << *p << endl;
    *p = 42;
    cout << "*p=" << *p << endl;
    /* here we forgot to delete 'p' - and now we're having a memory leak */

    cout << "successfully reached the end of checkPlainPointer()" << endl;
}

void checkSimplestSmartPointer() {

}