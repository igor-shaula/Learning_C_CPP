#include "SimplestSmartPointer.hpp"

void checkPlainPointer();

void checkSimplestSmartPointer();

void testPointersInStack();

void checkPointersInHeap();

int main() {
//    checkPlainPointer();
//    checkSimplestSmartPointer();

    testPointersInStack();
    checkPointersInHeap();
    return 0;
}

void println(string const &s) {
    cout << s << endl;
}

void check(bool isOk, const string &what) {
    string result = isOk ? "+OK" : "FAILED";
    println("\t" + result + " : " + what);
}

void testPointersInStack() {
    int value = 5;
    int *a = &value;
    check(*a == value, "a");
    int *b = a;
    check(*b == value, "b");
    println("FINISHED testPointersInStack()");
}

void checkPointersInHeap() {

    /* test of creation 1 - standard type */
    int value = 5;
    int *ip1 = new int(value);
    check(*ip1 == value, "ip1");
    int *ip2; // unassigned / undefined
    check(ip2, "ip2");
    cout << "ip2 = " << ip2 << endl;
//    if (ip2 != nullptr) cout << "*ip2 = " << *ip2 << endl; // interrupted by signal 11: SIGSEGV

    /* test of creation 2 - special type */
    auto *s1 = new string("hello");
    SimplestSmartPointer ssp1(s1);
    check(*s1 == *ssp1, "ssp1");
    auto *s2 = new string("");
    SimplestSmartPointer ssp2(s2);
    check(*s2 == *ssp2, "ssp2");
    auto *s3 = new string("\0");
    SimplestSmartPointer ssp3(s3);
    check(*s3 == *ssp3, "ssp3");

    /* test of deletion */

    /* test of access */

    println("FINISHED checkPointersInHeap()");
}

void checkPlainPointer() {
    /* 1 - created with assignment operator */
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