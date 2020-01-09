// При использовании шаблонов иногда надо писать typename у типов - когда и зачем это делать?

#include <iostream>
template<class T>
inline void printElements(const T &coll, const char *optcstr = "") {
    typename T::const_iterator pos;

    std::cout << optcstr;
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}

/* Проблема в том, что T::const_iterator — зависимое имя: оно зависит от параметра шаблона T.
 * В этой точке компилятор не знает, каким будет T, и не может предсказать,
 * будет ли T::const_iterator именем типа или, например, именем статического поля или вообще шаблона.
 * Поэтому он и не пытается угадать, и предполагает, что это поле.
 * Если же ему подсказать, он будет предполагать, что T::const_iterator — это тип,
 * и поймёт, что typename T::const_iterator pos; — объявление переменной.
 *
 * Почему же компилятор не может подождать с выяснением смысла выражения T::const_iterator до того момента,
 * когда тип T будет уже известен (то есть, до момента разворачивания шаблона с конкретным типом T)?
 * А вот почему: на момент применения шаблона тип T имеет право быть ещё не определён!
 * И ещё он может зависеть от самого шаблона. Так что откладывать выяснение смысла выражения нельзя. Пример:
 *  template <class T>
    class comparable<T> {
    bool compare(T& other) { return this == other; }
    };
    class length : public comparable<length> // в этой точке для comparable тип T ещё не известен полностью!
    {...};
 * Пример кода, иллюстрирующего «скользкие» моменты, приведён ниже.
 * Он не компилируется gcc (так как нету полагающегося по стандарту typename),
 * но более либеральный MSVC 2012 его компилирует и выполняет.
 * typename для того и нужен, чтобы исключить подобные сюрпризы.
 */
//#include "stdafx.h" // нужно для MSVC
#include <iostream>
using namespace std;

template<class T>
struct A {
    void f() {
        // если T::iterator - тип, это предварительное объявление функции
        // если T::iterator - число, это объявление переменной с инициализацией
        int x(T::iterator);
    }
    void g() {
        int x = 5;
        {
            // если T::iterator - шаблон, принимающий числовой аргумент,
            // это инстанциация шаблона в переменную x, перекрывающую x
            // за фигурными скобками
            // если T::iterator -- экземпляр класса с перегруженным оператором <,
            // это сравнение T::iterator с нулём, а затем сравнение результата
            // со значением переменной x!
            T::iterator<0> x;
            // Кто-то всё ещё сомневается, что C++ - непредсказуемый язык?
        }
    }
};

struct T1 {
    typedef int iterator;
};

struct T2 {
    static const int iterator = 5;
};

struct T3 {
    template<int C>
    struct iterator {
        iterator() { cout << "constructing template with C = " << C << endl; }
    };
};

struct T4 {
    struct Titerator {
        Titerator operator<(int value) {
            cout << "in operator < " << value << endl;
            return Titerator();
        }
        bool operator>(int value) {
            cout << "in operator > " << value << endl;
            return false;
        }
    };
    static Titerator iterator;
};

T4::Titerator T4::iterator = T4::Titerator();

int main(int argc, char *argv[]) {
    A<T1> a1;
    a1.f();
    A<T2> a2;
    a2.f();
    A<T3> a3;
    a3.g();
    A<T4> a4;
    a4.g();
    /* Результат работы таков:
    constructing template with C = 0
    in operator < 0
    in operator > 5
    */
    return 0;
}