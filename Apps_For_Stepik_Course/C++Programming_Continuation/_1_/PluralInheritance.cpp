#include <iostream>

/* SAMPLE 1 */

struct A {
    virtual ~A() = default;
};

struct C {
    virtual ~C() = default;
    static void foo() {
        std::cout << "C: " << __func__ << std::endl;
    }
};
struct D : A, C {
    virtual ~D() = default;

    static void bar() {
        std::cout << "D: " << __func__ << std::endl;
    }
};
struct B : A {
    virtual ~B() = default;

    static void baz() {
        std::cout << "B: " << __func__ << std::endl;
    }
};
struct E : B, C, D {
    virtual ~E() = default;
};

void test1sample();
int main() {
    test1sample();
    E e;
    std::cout << sizeof e << std::endl;
    e.baz();
    D &d = e;
    d.foo();

    return 0;
}
void test1sample() {

}
