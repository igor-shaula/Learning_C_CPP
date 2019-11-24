/*
Для ScopedPtr мы запретили копирование, однако, копирование можно и разрешить.
Это позволит реализовать более продвинутый умный указатель — SharedPtr.
Он отличается от ScopedPtr тем, что кроме хранения указателя на объект, он хранит еще и счетчик ссылок
(количество объектов SharedPtr, которые хранят один и тот же указатель).

Имея такой счетчик, мы можем определить момент, когда на объект, выделенный в куче,
не останется больше ссылок (когда счетчик ссылок станет равным 0), и освободить память.

Поддержка счетчика ссылок состоит из нескольких частей:

в конструкторе SharedPtr от ненулевого указателя мы инициализируем счетчик ссылок в 1
(конструктор создает первый SharedPtr, который хранит указатель),
в конструкторе копирования мы увеличиваем счетчик ссылок на 1,
если копируемый SharedPtr содержит ненулевой указатель
(конструктор копирования создает еще один SharedPtr с указателем на тот же самый объект),
в деструкторе мы уменьшаем значение счетчика на 1, если в объекте SharedPtr хранится ненулевой указатель
(мы удаляем один SharedPtr, который указывает на объект в куче),
оператор присваивания:
уменьшает счетчик ссылок левого операнда на 1, если внутри левого SharedPtr хранится ненулевой указатель,
увеличивает счетчик правого SharedPtr на 1, если в правом SharedPtr хранится ненулевой указатель
(обычное дело для оператора присваивания — сначала освобождаем старые ресурсы, потом выделяем новые,
но при этом нужно быть особенно внимательным с присваиванием самому себе).
Для класса SharedPtr могут оказаться полезными следующие методы
(кроме операторов * и ->, конструктора копирования, оператора присваивания, деструктора и конструктора):
метод get, как и в случае со ScopedPtr,
метод reset — аналогичен reset у ScopedPtr, но освобождает память,
только если счетчик ссылок после декремента равен 0.
*/

#include "SharedPtr.hpp"

void runOtherTests();

void checkPointersInHeap();

int main() {
    runOtherTests();
//    checkPointersInHeap();
    return 0;
}

void println(string const &s) {
    cout << s << endl;
}

void check(bool isOk, const string &what) {
    string result = isOk ? "+OK" : "FAILED";
    println("\t" + result + " : " + what);
}

void runOtherTests() {

    SharedPtr p1;
    println("p1");
//    SharedPtr p(nullptr);
//    println("p-null");
    p1.reset(nullptr);
    println("p1-reset-null");
    {
        SharedPtr p2(new Number(1.1));
        println("p2");
        SharedPtr p3(new Number(1.2));
        println("p3");
        SharedPtr p4(p2);
        println("p4");
//        const SharedPtr& p4(p2);
        SharedPtr p5;
        println("p5");
        p5 = p2;
        println("p5=p2");
        p5 = p4;
        println("p5=p4");
        p1 = p5;
        println("p1=p5");
        p3.reset(nullptr);
        println("p3.reset");
        p3 = p5;
        println("p3=p5");
        p5.reset(nullptr);
        println("p5.reset");
        SharedPtr p6;
        println("p6");
        SharedPtr p7;
        println("p7");
        p7 = p7;
        println("p7=p7");
        p7.reset(nullptr);
        println("p7.reset-null");
        p7.reset(new Number(1.3));
        println("p7.reset-new");
        // p7.reset(new Expression("expr3"));
        SharedPtr p8(new Number(1.4));
        println("p8");
        // SharedPtr p8(new Expression("expr4"));
        p8.reset(nullptr);
        println("p8.reset-null");
    }
    p1 = p1;
    println("p1=p1");
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
    SharedPtr sp1(e1);
    Expression *sp1got = sp1.get();
    check(sp1got->evaluate() == *d1, "SP - constructor - value changed");

    /* todo: why the next line leads to seg.fault even when proper constructor is present ??? */
//    Expression *sp2got = sp2.get();
//    check(sp2got->evaluate() == *d1, "SP - constructor for second pointer - value assigned");

    /* leads to interrupted by signal 11: SIGSEGV */
//    Expression *en2; // explicitly not initialized
//    SharedPtr sp2(en2);
//    check(sp2.get() != nullptr, "SP - assigned address of non-defined object in heap");
//    cout << sp2.get()->evaluate() << endl;

    /* leads to interrupted by signal 11: SIGSEGV */
//    SharedPtr sp3(nullptr); // should not work because we have special safety check before assignment
//    check(sp3.get() == nullptr, "SP - assigned nullptr");

    /* impossible to compile - and that's normal for ScopedPtr */
//    SharedPtr sp4 = sp1; // copying constructor is forbidden for ScopedPtr
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
        SharedPtr sp3(e3);
        e3ptr = sp3.get();
    }
//    cout << e3->evaluate() << endl; // interrupted by signal 11: SIGSEGV - and that's correct
//    cout << e3ptr->evaluate() << endl; // interrupted by signal 11: SIGSEGV - and that's correct
    cout << "e3 == nullptr : " << (e3 == nullptr) << endl; // and this is really strange - WHY ???
    cout << "e3 == e3ptr : " << (e3 == e3ptr) << endl;

    println("FINISHED checkPointersInHeap()");
}
/*
Катастрофическая невнимательность. Сразу написал все как надо, даже сказал сам себе
"в этой задаче фишка в том, что перед тем, как обращаться к чему-то через указатель
- надо сперва проверить что указатель ненулевой". И написал проверку. В двух ситуациях из трех.
Весь день ушел на то, чтобы вспомнить про третью ситуацию
и обезопасить ее от разыменований нулевого указателя.
Решается без статика, без вспомогательного класса.
Конструкция, содержащая уничтожения объекта и счетчика,
копипастом одинаковая в деструкторе, присвоении и ресете.
Любое разыменование - после проверки указателя на ненулевость.
Создание и инициализация - после проверки на существование указываемого объекта.

Задача не сложна, но требует внимательности и понимания каждого действия.
Вот потенциальные ошибки:
1. Хранить счетчик по значению (следовательно, у каждого объекта свой — так не должно быть).
2. Забывать освобождать память (деструктор, оператор присвоения и reset).
3. Удалять указатель там, где нужно было только занулить (те же места).

use Valgrind to find memory leak

use pointer to counter instead of counter directly

use swap() function from previous samples (for operator=)

... this is not the end of hints
*/