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

void checkPointersInHeap();

int main() {
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

void checkPointersInHeap() {
    println("STARTING checkPointersInHeap()");

    double value = 1.2;
    auto *dp1 = new double(value);
    check(*dp1 == value, "double - assigned address of object in heap");

    double *dp2 = dp1;
    check(*dp2 == value, "double - assigned copied address of object in heap");

    auto *d1 = new double(1.2);
    Expression *e1 = new Number(1.2);
    ScopedPtr sp1(e1);
    Expression *sp1got = sp1.get();
    check(sp1got->evaluate() == *d1, "SP - constructor - value changed");
    check(sp1.getCounter() == 1, "SP - constructor - counter changed");

    /* todo: why the next line leads to seg.fault even when proper constructor is present ??? */
//    ScopedPtr sp2(e1); // creating second pointer for the same object
//    sp2.setCounter() = 2; // only to check upcoming test
//    Expression *sp2got = sp2.get();
//    check(sp2got->evaluate() == *d1, "SP - constructor for second pointer - value assigned");
//    check(sp2.getCounter() == 2, "SP - constructor for second pointer - counter increased");
    /* todo: why counter is always 1 ??? */

    /* leads to interrupted by signal 11: SIGSEGV */
//    Expression *en2; // explicitly not initialized
//    ScopedPtr sp2(en2);
//    check(sp2.get() != nullptr, "SP - assigned address of non-defined object in heap");
//    cout << sp2.get()->evaluate() << endl;

    /* leads to interrupted by signal 11: SIGSEGV */
//    ScopedPtr sp3(nullptr); // should not work because we have special safety check before assignment
//    check(sp3.get() == nullptr, "SP - assigned nullptr");

    /* impossible to compile - and that's normal for ScopedPtr */
//    ScopedPtr sp4 = sp1; // copying constructor is forbidden for ScopedPtr
//    check(*sp1 == *sp4, "SP - copying instance of ScopedPtr");

    double newValue = 2.3;
    Expression *e2 = new Number(newValue);
    sp1.reset(e2);
    Expression *e2changed = sp1.get();
    check(e2changed->evaluate() == newValue, "SP - test of reset()");

    Expression *e2release = sp1.release();
    check(e2release->evaluate() == newValue, "SP - test of release() - value changed");
    check(sp1.get() == nullptr, "SP - test of release() - pointer nullified");

    /* todo: find a way to correctly test destructors - single and multiple invocations of them */

    Expression *e3 = new Number(3.4);
    Expression *e3ptr;
    {
        ScopedPtr sp3(e3);
        e3ptr = sp3.get();
    }
//    cout << e3->evaluate() << endl; // interrupted by signal 11: SIGSEGV - and that's correct
//    cout << e3ptr->evaluate() << endl; // interrupted by signal 11: SIGSEGV - and that's correct
    cout << "e3 == nullptr : " << (e3 == nullptr) << endl; // and this is really strange - WHY ???
    cout << "e3 == e3ptr : " << (e3 == e3ptr) << endl;

    println("FINISHED checkPointersInHeap()");
}