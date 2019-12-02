#include "TemplateSpecialization.hpp"
#include <iostream>

using namespace std;

/* sample of using template specialization for classes
 * let's think about copying of types - for most of custom types we'll have to use copying in loops,
 * but for many primitive types we can use per-byte copying 'memcpy' which is much faster ..
 * the question is how to differentiate these types - and here specialization becomes very handy
 */
template<typename T>
struct PerByteCopyable { // this is default template for all types
    static const bool value = false; // 'memcpy' is prohibited - we have to use loop-based custom copying
};
template<>
struct PerByteCopyable<char> { // we can write similar specializations for other needed primitive types
    static const bool value = true; // now 'memcpy' will be used during copying operations
};
// the benefit here is that all functions using these templates will always react on specialization

/* DIFFERENCE BETWEEN OVERLOADING AND SPECIALIZATION */

template<class T>
void foo(T a, T b) { cout << "first for same types" << endl; }
// in fact only this variant will be used in given sample of invocation in main() - because it uses only 1 type

template<class T, class V>
void foo(T a, V b) { cout << "overloaded for different types" << endl; }
// overloaded variant of our first function 'foo' - the main point here is that it uses 2 different types

template<>
void foo<int, int>(int a, int b) { cout << "specialized only for ints" << endl; }
// specialization for our function 'foo' - but note that for first variant as it uses only one type int like T

void testTypesDetection(); // needed for task in the end of the lesson chain

int main() {
    foo(3, 4); // IDE points to specialized function but IN FACT IT WILL NOT BE SELECTED BY COMPILER
    /* OVERLOADING WORKS FIRST in compilation process - that's why selection might not be easily visible */
    testTypesDetection();
    return 0;
}

template<typename T1, typename T2>
struct SameType {
    static const bool value = false;
};
template<typename T>
struct SameType<T, T> {
    static const bool value = true;
};
// and yes it works! so simple when you understand the language!

struct Dummy {
};
typedef int type;
void testTypesDetection() {
    cout << SameType<int, int>::value << endl; // выведет 1, т. е. true
    cout << SameType<int, type>::value << endl; // 1, type == int
    cout << SameType<int, int &>::value << endl; // 0, int и ссылка на int - различные типы
    cout << SameType<Dummy, Dummy>::value << endl; // 1
    cout << SameType<int, const int>::value << endl; // 0, const - часть типа
}

/*
Наверное, стоило сначала дать общие понятия о том, как происходит выбор функции на этапе компиляции:
- приоритет всегда отдается нешаблонным функциям.
 Если находится нешаблонная функция, которая удовлетворяет всем параметрам, то вызовется именно она;
- если среди нешаблонных функций не нашлось подходящей,
 то компилятор рассматривает различные перегрузки базового шаблона (base template function),
 не учитывая специализаций, и выбирает среди перегрузок;
- если какая-то из перегрузок базового шаблона подошла,
 то далее компилятор проходится по ее специализациям и выбирает среди них.

Есть даже такой интересный пример Димова-Абрахамса. Пусть мы имеем три функции:

template void foo(T) { }
template void foo(T*) { }
template<> void foo(int*) { }

При исполнении кода:
int* p;
foo(p);
будет вызвана реализация №3. Оно и понятно.
 Первая и вторая функции являются теми самыми base template function — перегрузками базового шаблона.
 Третья функция здесь является специализацией второй функции при T*==int*.
 При разборе компилятор выбирает для аргумента int* функцию среди перегрузок — foo(T) и foo(T*)
 — и выбирает ту, что принимает указатель. Затем он перебирает ее специализации и обнаруживает, что есть одна строго для int*.

Совсем другая ситуация наступает, если мы меняем вторую и третью строки местами:

template void foo(T) { }
template<> void foo(int*) { }
template void foo(T*) { }

Тогда компилятор будет трактовать функцию foo(int*) во второй строчке, как специализацию первой функции foo(T) для T==int*.
 Тем не менее, он все равно начнет свой выбор с перебора перегрузок. Перегрузки реализованы в первой и третьей строчках,
 и среди foo(T) и foo(T*) для foo(int*) компилятор выберет foo(T*) — мы же передаем указатель.
 Далее он попробует пройтись по ее специализациям, которых в нашем коде нет, и ничего не найдет.
 Таким образом, будет вызвана третья функция.
*/