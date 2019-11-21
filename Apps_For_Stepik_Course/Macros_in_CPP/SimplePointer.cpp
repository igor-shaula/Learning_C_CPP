#include "SimplePointer.hpp"

void checkPointersInStack();

void checkPointersInHeap();

int main() {
    checkPointersInStack();
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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"

void checkPointersInStack() {
    println("STARTING checkPointersInStack()");
    int value = 5;
    int *a = &value;
    check(*a == value, "a");
    int *b = a;
    check(*b == value, "b");
    int *n; // unassigned / undefined
    check(n, "n");
    cout << "n = " << n << endl; // has to be random value but it's the same from launch to launch
//    if (n != nullptr) cout << "*n = " << *n << endl; // interrupted by signal 11: SIGSEGV

    // todo add here samples of using SimplePointer in stack

    println("FINISHED checkPointersInStack()");
}

#pragma clang diagnostic pop

void checkPointersInHeap() {
    println("STARTING checkPointersInHeap()");

    /* test of creation 1 - standard type */
    int value = 5;
    int *ip1 = new int(value);
    check(*ip1 == value, "ip1");
    int *ip2 = ip1;
    check(*ip2 == value, "ip2");

    /* test of creation 2 - special type */
    auto *s1 = new int(21);
    SimplePointer sp1(s1);
    check(*s1 == *sp1, "sp1");
    auto *s2 = new int;
    SimplePointer sp2(s2);
    check(*s2 == *sp2, "sp2");

    /* copying pointer wrapper */
    SimplePointer sp4 = sp1;
    check(*sp1 == *sp4, "sp4");

    /* using pointer wrapper for content modification */
    SimplePointer sp5 = sp2;
    int newValue = 42;
    *sp5 = newValue;
    check(*sp2 == newValue, "sp5");

    /* test of deletion */
    SimplePointer sp6 = sp2;
    int tmp1 = *sp2; // 42 after assigning from newValue
    delete &*sp6; // firstly getting inner *ptr_ and then taking its address
    check(*sp2 != tmp1, "sp6");

    /* multiple deletion */
    SimplePointer sp7 = sp1;
    int tmp2 = *sp1;
    delete &*sp7; // 1
    delete &*sp7; // 2
    check(*sp1 != tmp2, "sp7");

    println("FINISHED checkPointersInHeap()");
}