#include <iostream>

using namespace std;

void testAllVariants();

int main() {
    testAllVariants();
    return 0;
}

template<typename T>
void println(T const &value) {
    cout << value << endl;
}

void testAllVariants() {
    int a = 27;
    int const b = 412;
    int *pa = &a;

    // Выберите все случаи, где преобразование const_cast<> в правой части обязательно.
    int const c = a;
//    int const c = const_cast<int const &>(a);
    println(c);
    int d = (b);
//    int d = const_cast<int &>(b);
    println(d);
    int const *p1 = pa;
//    int const *p1 = const_cast<int const *>(pa);
    println(p1);
    int *const *p2 = &pa;
//    int *const *p2 = const_cast<int *const *>(&pa);
    println(p2);
//    int const **p3 = &pa; // only this cannot be compiled
//    int const **p3 = const_cast<int const **>(&pa);
//    println(p3);
    int const *const *p4 = &pa;
//    int const *const *p4 = const_cast<int const *const *>(&pa);
    println(p4);
    // in fact they all compile this way and in all cases except p3 const_cast can be omitted
}