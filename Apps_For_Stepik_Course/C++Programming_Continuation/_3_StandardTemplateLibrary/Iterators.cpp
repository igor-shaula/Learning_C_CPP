#include <vector>
#include <iostream>
/* iterator = object for accessing an element of a sequence\
 * syntactically iterator is like a pointer\
 * there are 5 categories of iterators:
 * 1. Random Access Iterators - have ++ , -- , arithmetic , < , <= , > , >=
 * containers that have RAI : array , vector , deque \
 * 2. Bidirectional Iterators - have ++ and -- operators only\
 * containers that have bidirectional iterators : list , set , map
 * 3. Forward Iterators - have only ++ operation possibility
 * containers with FI: forward_list , unordered_set , unordered_multiset , unordered_map , unordered_multimap
 * 4. Input Iterators - have only ++ and are read-only
 * 5. Output Iterators - have only ++ and are write-only
 * А оператор == ведь для всех итераторов определен? - YES
 */

void showIterators() {
    /* all iterators have these 3 functions:
     * void advance(Iterator & i , size_t n);
     * size_t distance(Iterator i , Iterator j);
     * void iter_swap(Iterator i , Iterator j); - effect is equal to standard swap(*i , *j);
     * iter_swap(i, j) ничем не отличается от swap(*i, *j)
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