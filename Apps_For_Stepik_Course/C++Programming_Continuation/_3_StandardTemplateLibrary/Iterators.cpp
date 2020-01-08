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

int main() {
    showIterators();
    showDecreasingIterator();
    return 0;
}