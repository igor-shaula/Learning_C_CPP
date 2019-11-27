#include "ArrayTemplate2.hpp"
//#include "iostream"
#include <new>

struct A {
public:
    A(int b) : a(b) {}
    A(A const &other) {
        a = other.a;
    }
    int a = 9;
private:
    A();
    A &operator=(A const &);
};

int main() {
    Array<A> array(2, A(5));
/*
    A obj1(5);
    A *ptr1 = new A(3);
    A obj2(obj1);
//    template T<void()>

    new(ptr1) A(5);
    new(ptr1) A(obj1);
//    A *ptr2 = new(ptr1) A(7);

//    std::cout << "b:" << ptr1->a << std::endl;
//    std::cout << "obj2:" << obj2.a << std::endl;

    delete ptr1;
//    delete ptr2;
//    std::cout << "ptr2:" << ptr2->a << std::endl;
*/
    return 0;
}