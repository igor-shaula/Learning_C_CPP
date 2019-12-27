#include <iostream>
using namespace std;
template<class T>
void println(T const &value) {
    cout << value << endl;
}

/* common methods for all containers except 'array':
 * constructor from two arguments,
 * constructor from 'count' and 'defVal',
 * constructor from std::initializer_list<T>,
 * front(), back(),
 * push_back(), emplace_back(),
 * assign(),
 * insert(),
 * emplace(),
 * erase() from 1 or 2 iterators
 */

#include <array>
void showArray() {
    // std::array<T> is a wrapper over standard array with addition of STL container's API
    array<string, 2> a = {"one", "two"};
    println(a.size());
    println(a.data());
    println(a[1]);
    string s = "three";
    a = {"three", "four"};
    *(a.data()) = s; // <- how to set a new pointer into with non-const data()
    println(a.at(0));
}

#include <vector>
void showVector() {
    // std::vector<T> is a dynamic array with auto-resize during addition of new elements
    vector<string> v = {"one", "two"};
    println(v.size());
    println(v.capacity());
    println("at 1: " + v.at(1));
    v.resize(4);
    println(v.size());
    println(v.capacity());
    println("at 3: " + v.at(2));
    v.reserve(9);
    println(v.size());
    println(v.capacity());
    println(v.data());
    v.shrink_to_fit();
    println(v.size());
    println(v.capacity());
    /* стоит предпочитать emplace_back методу push_back хотя бы потому что вызывается не два последовательных конструктора, а один ?
     * - да, emplace_back эффективней.
     * - Впрочем компилятор может такое оптимизировать :) Так что часто без разницы.
     * - Если копировать тип дешево, то push_back может быть эффективней.
     * Т.е. для какого-нибудь vector<int> использовать emplace_back не имеет смысла.
     *
     * 1) Сначала вызывается конструктор string от const char*, тем самым создаётся временный объект типа string
     * 2) Метод push_back перегружен для принятия l-value и r-value ссылок.
     * Т.к. аргумент - временный объект, то приоритет отдаётся перегрузке, принимающей r-value.
     * 3) Внутри метода push_back будет вызван перемещающий конструктор с помощью placement-new.
     * (На самом деле в реализации STL g++ в перемещающей перегрузке метода push_back
     * вызывается метод emplace_back, в котором уже и будет вызван конструктор.
     * Больше, в общем-то ничего не происходит, если не говорить о расширении буфера в случае необходимости \
     *
     * Возможна ли вообще ситуация, когда нужно использовать push_back, а не emplace_back?
     * Разве emplace_back не охватывает случаи копирующего/перемещающего конструктора, причем с не меньшей эффективностью?
     * - да, использование push_back позволяет обозначить, что в данном месте мы передаём объект именно того типа,
     * который хранится в контейнере.
     * Т.е. лучше разделять эти два метода, т.к. это улучшает читабельность и типобезопасность кода.
     *
     * Если не нужно, чтобы данные располагались в памяти непрерывным блоком как в массиве,
     * то лучше использовать std::deque вместо vector.
     * В deque данные можно эффективно вставлять не только в конец, но и в начало,
     * с ним не будет копирования данных (и инвалидации итераторов) при изменении размеров.
     * Однако, доступ к элементам чуть дольше (вместо одного разыменовывания указателя, потребуется сделать два).
     * - std::vector зачастую быстрее.
     * Если очень хочется, можно реализовать свой аналог deque на паре векторов.
     * Зависит от задачи, но обычно vector эффективней.
     * - Инвалидация итераторов происходит. Ивалидации ссылок и указателей - не происходит.
     */
}

#include <deque>
void showDeque() {
    // 'deque' = double ended queue - allows to add new elements to either side for O(1) time \
    // finding an element by [i] operator works much slower than in array or vector \
    // there are different implementations or STL containers - only headers are standard
    deque<string> d = {"one", "two"};
    d.emplace_back("three");
    d.emplace_front("zero");
    println(d[0]);
    println(d[2]);
    /* вопрос: можно ли считать ошибкой спецификации то, что у метода std::deque::push_back()
     * указана константная сложность (именно константная, а не амортизированная константа)?
     * При том, что константа указана также и для случайного доступа.
     * - push_back действительно за константу работает.
     * Добавление элемента может потребовать выделение нового блока, но блок тоже константного размера.
     * - зато добавление указателя на новый блок в "список" этих блоков
     * (который вовсе не список, а нечто, обладающее константным временем доступа по индексу)
     * оно явно должно быть аммортизированной константой. Либо я чего-то не понимаю.
     * - Т.е. учитываются только операции с объектами в контейнере.
     * В этом смысле получается O(1)O(1) в худшем.
     * Если считать всё остальное, то да, тут получится только амортизированная сложность.
     */
}

#include <list>
void showList() {
    // std::list<T> in fact is double-linked list \ all insertions & deletions take O(1) time
    list<string> l = {"Lone", "Ltwo"};
    println(l.front());
    l.emplace_front("Lzero");
    println(l.front());
    println(l.back());
    l.emplace_back("Lthree");
    println(l.back());
    /* http://en.cppreference.com/w/cpp/container/list/splice -
     * Почему в случае (3)﻿будет линейная сложность?
     * - потому что нужно обновить size.
     */
    // question for now - how to get [i] element from a 'list' ??? iterators or range-based for:
    // 'list' does not have any API to get i-element because it would require linear time O(N)
    // for 'vector' searching is done for constant time - but for list - not

    // range-based for: works with all containers, non-STL arrays & also std::initializer_list
    for (string &s:l) // re-pointing this reference on each iteration
        println(s);
    println(l.size());
    // iterators are present in all STL containers - and their API is generic for all of them:
    list<string>::iterator i = l.begin(); // this type can be replaced with 'auto'
    for (; i != l.end(); ++i) // like with pointers - l.end() points just outside container's scope
        if (*i == "Ltwo") // finding position of certain element - it's like shifting data's pointer
            break;
    l.erase(i); // here we delete one of the element which has just been found
    println("size after deletion: " + l.size());
    auto last = l.end(); // points to memory right next after the end of our container
    println(*(--last)); // now pointing to the last element of our sequence container
}

#include <forward_list>
void showForwardList() {
    // std:forward_list<T> looks like restricted variant of 'list' where pointers move only forwards
    forward_list<string> fl = {"one", "two"};
    fl.emplace_front("zero"); // places to the very first position
    println(fl.front());
    fl.push_front("minus one"); // ALSO places to the very first position
    println(fl.front());
    /* some useful methods:
     * insert_after() & emplace_after() instead of insert() & emplace()
     * before_begin() & cbefore_begin() - for getting iterators (normal and constant)
     * push_front(), emplace_front(), pop_front()
     * splice_after()
     * merge(), remove(), remove_if(), reverse(), sort(), unique() - will see those some later
     */
}

int main() {
    showArray();
    showVector();
    showDeque();
    showList();
    showForwardList();
    return 0;
}