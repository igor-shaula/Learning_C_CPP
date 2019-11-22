/*
На предыдущих неделях вы уже набили достаточно шишек на ручном управлении памятью.
Пришло время задуматься о более разумном подходе.
Начнем с довольно простого случая — рассмотрим динамические объекты,
время жизни которых ограничено блоком ({} — ограничивают блок в C++).
Указатель на такой динамический объект внутри блока можно "связать" со временем жизни объекта на стеке:
достаточно сохранить этот указатель в некотором объекте на стеке,
а в деструкторе этого объекта вызвать delete.
Так как деструктор объекта, созданного на стеке, вызывается автоматически при выходе из блока,
то delete тоже будет вызван автоматически.

Такой класс-обертку мы будем называть ScopedPtr.
Стоит заметить, что копирование такого объекта может приводить к серьезным проблемам,
например, к повторному освобождению памяти
(два объекта хранят внутри один и тот же указатель и вызов delete будет сделан дважды).
Поэтому нужно запретить вызов конструктора копирования и оператора присваивания таких объектов.
Добиться этого можно объявив их в private секции класса.
При этом даже не нужно их реализовывать — снаружи класса никто не сможет их вызвать,
а внутри класса мы этого делать не будем.

Какой интерфейс может быть у такого класса ScopedPtr?
Кроме уже известных вам операторов * и ->, деструктора и конструктора,
полезными могут оказаться следующие методы:
    get — возвращает указатель, сохраненный внутри ScopedPtr
(например, чтобы передать его в какую-то функцию);
    release — забирает указатель у ScopedPtr и возвращает значение этого указателя,
после вызова release ScopedPtr не должен освобождать память
(например, чтобы вернуть этот указатель из функции);
    reset — метод заставляет ScopedPtr освободить старый указатель, а вместо него захватить новый
(например, чтобы переиспользовать ScopedPtr, так как оператор присваивания запрещен).
*/

#include "ScopedPtr.hpp"

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
    double value = 5;
    double *a = &value;
    check(*a == value, "double - assigned address of object in stack");
    double *b = a;
    check(*b == value, "double - assigned copied address of object in stack");
    double *n; // unassigned / undefined
    check(n, "double - only declared without definition");
    cout << "n = " << n << endl; // has to be random value but it's the same from launch to launch
//    if (n != nullptr) cout << "*n = " << *n << endl; // interrupted by signal 11: SIGSEGV
//    ScopedPtr sp(&value);
//    check(*sp == value, "SP - assigned address of value in heap");

    println("FINISHED checkPointersInStack()");
}

#pragma clang diagnostic pop

void checkPointersInHeap() {
    println("STARTING checkPointersInHeap()");

    double value = 1.2;
    auto *dp1 = new double(value);
    check(*dp1 == value, "double - assigned address of object in heap");

    double *dp2 = dp1;
    check(*dp2 == value, "double - assigned copied address of object in heap");

    auto *d1 = new double(1.2);
    Expression *en1 = new Number(1.2);
    ScopedPtr sp1(en1);
    Expression *en1got = sp1.get();
    check(en1got->evaluate() == *d1, "SP - assigned address of object in heap");

//    auto *d2 = new double;
//    ScopedPtr sp2(d2);
//    check(*d2 == *sp2, "SP - assigned address of non-defined object in heap");

    ScopedPtr sp3(nullptr);
    check(sp3.get() == nullptr, "SP - assigned nullptr");

//    ScopedPtr sp4 = sp1;
//    check(*sp1 == *sp4, "SP - copying instance of ScopedPtr");
//
//    ScopedPtr sp5 = sp2;
//    double newValue = 2.3;
//    *sp5 = newValue;
//    check(*sp2 == newValue, "SP - using pointer wrapper for content modification");
//
//    ScopedPtr sp6 = sp2;
//    double tmp1 = *sp2; // 42 after assigning from newValue
//    delete &*sp6; // firstly getting inner *ptr_ and then taking its address
//    check(*sp2 != tmp1, "SP - correct/single deletion");
//
//    ScopedPtr sp7 = sp1;
//    double tmp2 = *sp1;
//    delete &*sp7; // 1
//    delete &*sp7; // 2
//    check(*sp1 != tmp2, "SP - multiple deletion");

    println("FINISHED checkPointersInHeap()");
}