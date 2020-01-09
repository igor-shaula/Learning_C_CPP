#include <vector>
#include <iostream>
/* iterator = object for accessing an element of a container\
 * syntactically iterator is like a pointer\
 * there are 5 categories of iterators:
 * 1. Random Access Iterators - have ++ , -- , arithmetic , < , <= , > , >= (the most advanced iterators)
 * containers that have RAI : array , vector , deque \
 * 2. Bidirectional Iterators - have ++ and -- operators only\
 * containers that have bidirectional iterators : list , set , map , multiset , multimap
 * 3. Forward Iterators - have only ++ operation possibility
 * containers with FI: forward_list , unordered_set , unordered_multiset , unordered_map , unordered_multimap
 * 4. Input Iterators - have only ++ and are read-only
 * 5. Output Iterators - have only ++ and are write-only
 * А оператор == ведь для всех итераторов определен? - YES
 * also, by the way, simple pointers of arrays act like random access iterators\
 * bidirectional iterators mainly differ from RAI in ability to shift only by ONE element at a time\
 * forward iterators differ from bidirectional in ability to move in only ONE direction\
 */

void showIterators() {
    /* all iterators have these 5 small algorithms/functions:
     * 1. void advance(Iterator & i , size_t n);
     * 2. size_t distance(Iterator i , Iterator j);
     * 3. void iter_swap(Iterator i , Iterator j); - effect is equal to standard swap(*i , *j);
     * iter_swap(i, j) ничем не отличается от swap(*i, *j)
     * for advance() and distance() RAI will work for constant time, all others - for linear time\
     *
     * 4. std::next(it) позволяет получить следующий за it итератор;
     * 5. std::prev(it) позволяет получить итератор идущий перед it.
     * так же как и std::advance эти методы не проверяют выход за границу последовательности — это обязанность программиста.
     *
     * В качестве типа для Distance могут быть арифметические типы с знаком, например, int.
     * Таким образом алгоритм std::advance можно использовать не только для сдвига итератора вперёд,
     * но и для сдвига назад (для этого нужен как минимум двунаправленный итератор):
     * std::advance(it, -5); // сдвиг на 5 позиций назад
     *
     * А для чего эти методы нужны? Если мы используем next, то предполагаем, что у итератора есть operator++. Получается, что данный метод чисто для красоты?
       - да, у всех операторов есть ++. Не для красоты, а для удобства. Например,
        Iterator first = begin();
        // хочу создать итератор следующий за first
        Iterator second = first;
        ++first;
        Вместо этого можно написать:
        Iterator second = std::next(first);
     */
}

/* advance увеличивает итератор, а можно ли его уменьшить?
 * кажется, можно уменьшить, если итератор - это BidirectionalIterator */
void showDecreasingIterator() {
    std::vector<int> v = {100, 200, 300};
    // насчет "передвинуть на заданное количество позиций вперед"
    auto it = v.end();
    std::advance(it, /*здесь int в MSVC2015, не size_t*/ -3);
    std::cout << *it << std::endl; // 100
    // Насчёт "f должен идти не позже, чем l"
    std::cout << /*ptrdiff_t в MSVC2015, не size_t*/ std::distance(v.end(), v.begin()) << std::endl; // -3
}

/* every iterator has the following categories - inside iterator.h there are following structures:
 * template<class Iterator>
 * struct iterator_traits {
 *      typedef difference_type     Iterator::difference_type; // for all non-RAI this is void
 *      typedef value_type          Iterator::value_type;
 *      typedef pointer             Iterator::pointer;
 *      typedef reference           Iterator::reference;
 *      typedef iterator_category   Iterator::iterator_category; // RAI, BDI, FI, II, OI
 * };
 *
 * specialization for upper template - used for pointers only
 * this specialization is the only reason for upper structure's very existence
 *
 * template<class T>
 * struct iterator_traits<T *> {
 *      typedef difference_type     ptrdiff_t; // what is it ???
 *      typedef value_type          T;
 *      typedef pointer             T*;
 *      typedef reference           T&;
 *      typedef iterator_category   random_access_iterator_tag;
 * };
 */

using namespace std;
void showIteratorTraits() {
    vector<int> vector = {1, 2, 3, 4, 5};
    // the question is how to use these iterator traits - with specified types (not 'auto')
    auto iBegin = vector.begin();
    auto iEnd = vector.end();
    auto iDistance = distance(iBegin, iEnd);
    cout << iDistance << endl; // 5 in result for given vector
}

/* ? Что значит разность двух итераторов, если шаблон определен для одного итератора. Откуда там второй появился?
 * - Мы с использованием шаблона определяем класс итератора для нашего контейнера.
 * Дальше мы можем использовать несколько объектов данного класса.
 * ? Мы определили класс итератора. Он один там. А разность между между ним и чем имеется ввиду?
 * - У нас есть класс итератора. Может быть много итераторов - объектов данного класса.
 * Например, у нас есть список, есть класс итератора этого списка.
 * Есть итераторы этого класса: на начало списка, на конец списка, на середину списка...
 * Вот для этих итераторов (которые все одного класса) можно считать разность. Это похоже на арифметику указателей.
 * = теперь понятно. В нем можно хранить разницу:
 * typename std::iterator_traits<U>::difference_type n = std::distance(first_iterator, last_iterator);
 * */

#include <iterator>
/* there are 5 well known iterator categories (as types):
    struct random_access_iterator_tag {};
    struct bidirectional_iterator_tag {};
    struct forward_iterator_tag {};
    struct input_iterator_tag {};
    struct output_iterator_tag {};
 */
// now how can we use these iterator categories - via most suitable overloaded function selection:
template<class I>
void advanceImpl(I &i, size_t n, random_access_iterator_tag) { // setting specialization in overloading
    i += n; // doing wanted shift in only one operation - in constant time
}
template<class I>
void advanceImpl(I &i, size_t n, ...) { // this overloaded form will have the lowest priority among all
    for (size_t k = 0; k != n; ++k, ++i); // traversing container in linear time
}
template<class I>
void advance(I &i, size_t n) {
    advanceImpl(i, n, iterator_traits<I>::iterator_category()); // some magic happens here:
    // object is created - with type dependent from type I - it will be RAI if possible
}

int main() {
    showIterators();
    showDecreasingIterator();
    showIteratorTraits();
    return 0;
}