#include <iostream>

void test1sample();

void test2sample();

int main() {
    test1sample();
    test2sample();
    return 0;
}
void test1sample() {
    struct A {};
    struct C {
        static void fC() { std::cout << "C: " << __func__ << std::endl; }
    };
    struct D : A, C {
        static void fD() { std::cout << "D: " << __func__ << std::endl; }
    };
    struct B : A {
        static void fB() { std::cout << "B: " << __func__ << std::endl; }
    };
    struct E : B, C, D {};

    E e;
    std::cout << sizeof e << std::endl;
    e.fB();
    D &d = e;
    d.fC();
}
void test2sample() {
    struct A {};
    struct B : A {};
    struct C {
        static void foo() {}
    };
    struct D : A, C {};
    struct E : B, C, D {};

    E e;
//    e.C::foo(); // <----- ‘C’ is an ambiguous base of ‘E‘
}