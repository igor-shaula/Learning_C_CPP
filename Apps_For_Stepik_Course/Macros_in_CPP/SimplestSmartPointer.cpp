#include "SimplestSmartPointer.hpp"

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

    // todo add here samples of using SimplestSmartPointer in stack

    println("FINISHED checkPointersInStack()");
}

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
    SimplestSmartPointer ssp1(s1);
    check(*s1 == *ssp1, "ssp1");
    auto *s2 = new int;
    SimplestSmartPointer ssp2(s2);
    check(*s2 == *ssp2, "ssp2");

    /* copying pointer wrapper */
    SimplestSmartPointer ssp4 = ssp1;
    check(*ssp1 == *ssp4, "ssp4");

    /* using pointer wrapper for content modification */
    SimplestSmartPointer ssp5 = ssp2;
    int newValue = 42;
    *ssp5 = newValue;
    check(*ssp2 == newValue, "ssp5");

    /* test of deletion */
    SimplestSmartPointer ssp6 = ssp2;
    int tmp1 = *ssp2; // 42 after assigning from newValue
    delete &*ssp6; // firstly getting inner *ptr_ and then taking its address
    check(*ssp2 != tmp1, "ssp6");

    /* multiple deletion */
    SimplestSmartPointer ssp7 = ssp1;
    int tmp2 = *ssp1;
    delete &*ssp7; // 1
    delete &*ssp7; // 2
    check(*ssp1 != tmp2, "ssp7");

    println("FINISHED checkPointersInHeap()");
}