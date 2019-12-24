// these abilities have always been present in Java but for C++ the've been added only in new standard

#include <iostream>
struct SomeType {
    SomeType(int n) : number(n) {}
    SomeType() : SomeType(42) {}; // somewhat strange syntax - not so simple delegation like in Java
private:
    int number;
};
struct SomeClass {
    SomeClass() {}
    explicit SomeClass(int newValue) : value(newValue) {}
private:
    int value = 9; // default value is overwritten only in special constructor
};
struct BaseClass {
    BaseClass(int value) {}
};
struct DerivedClass : BaseClass {
    using BaseClass::BaseClass; // very strange syntax with double BaseClass
};

// using можно применять не только к конструкторам, но и к другим полям и методам класса. Например:
struct A {
protected:
    void f() { std::cout << "A::f()\n"; }
    int value;
};
struct B : A {
    using A::f;
    using A::value;
};
/* в данном примере поля и методы базового класса protected,
 * поэтому обращение к ним напрямую через наследованный класс невозможно
 * (можно только во внутренних методах класса).
 * А использование using в наследованном классе здесь делает их публичными.
 */
void showLastSample() {
    A a;
//    a.f(); // will not compile as this function is available only for child classes - not here
//    a.value = 1; // the same reason - this function is not visible here
    B b;
    b.f(); // now function from A is visible here - so via 'using' we can open it again
    b.value = 1; // in fact 'using' in child class destroys incapsulation
}