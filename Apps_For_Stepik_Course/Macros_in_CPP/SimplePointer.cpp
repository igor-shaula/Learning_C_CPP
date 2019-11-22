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
    check(*a == value, "int - assigned address of object in stack");
    int *b = a;
    check(*b == value, "int - assigned copied address of object in stack");
    int *n; // unassigned / undefined
    check(n, "int - only declared without definition");
    cout << "n = " << n << endl; // has to be random value but it's the same from launch to launch
//    if (n != nullptr) cout << "*n = " << *n << endl; // interrupted by signal 11: SIGSEGV
//    SimplePointer sp(&value);
//    check(*sp == value, "SP - assigned address of value in heap");

    println("FINISHED checkPointersInStack()");
}

#pragma clang diagnostic pop

void checkPointersInHeap() {
    println("STARTING checkPointersInHeap()");

    int value = 5;
    int *ip1 = new int(value);
    check(*ip1 == value, "int - assigned address of object in heap");

    int *ip2 = ip1;
    check(*ip2 == value, "int - assigned copied address of object in heap");

    auto *s1 = new int(21);
    SimplePointer sp1(s1);
    check(*s1 == *sp1, "SP - assigned address of object in heap");

    auto *s2 = new int;
    SimplePointer sp2(s2);
    check(*s2 == *sp2, "SP - assigned address of non-defined object in heap");

    SimplePointer sp3(nullptr);
    check(sp3.get() == nullptr, "SP - assigned nullptr");

    SimplePointer sp4 = sp1;
    check(*sp1 == *sp4, "SP - copying instance of SimplePointer");

    SimplePointer sp5 = sp2;
    int newValue = 42;
    *sp5 = newValue;
    check(*sp2 == newValue, "SP - using pointer wrapper for content modification");

    SimplePointer sp6 = sp2;
    int tmp1 = *sp2; // 42 after assigning from newValue
    delete &*sp6; // firstly getting inner *ptr_ and then taking its address
    check(*sp2 != tmp1, "SP - correct/single deletion");

    SimplePointer sp7 = sp1;
    int tmp2 = *sp1;
    delete &*sp7; // 1
    delete &*sp7; // 2
    check(*sp1 != tmp2, "SP - multiple deletion");

    println("FINISHED checkPointersInHeap()");
}