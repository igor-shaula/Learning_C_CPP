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

int main() {
    showArray();
    showVector();
    showDeque();
    return 0;
}