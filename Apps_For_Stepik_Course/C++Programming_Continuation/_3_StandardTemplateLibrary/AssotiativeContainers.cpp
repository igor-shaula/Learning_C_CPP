#include <iostream>
using namespace std;

template<class T>
void println(T const &value) {
    cout << value << endl;
}

/* assotiative containers can be ORDERED (><) & UNORDERED (require hash-function)
 * common methods for assotiative containers:
 * find by key , count by key , erase by key
 */

#include <set>
void showSet() {
    /* std::set<T> stores ordered multitude as binary search tree
     * operations of addition, deletion and search work for O(log(n)) time
     * values in set cannot be changed - because otherwise we'd have to re-balance binary tree
     * common methods for a set: lower_bound(), upper_bound(), equal_range()
     */
    set<int> primes = {1, 2, 3, 5, 7, 11}; // each value is UNIQUE here
    // now we'll try to find a value in this set - search works on iterators
    auto found = primes.find(7);
    if (found != primes.end()) // if not the end - than the value is found
        println("7 is found");
    // modification is done via insertions that return a pair with iterator & boolean:
    const pair<set<int>::iterator, bool> &pair = primes.insert(3); // we could use 'auto' here
    if (pair.second) println("3 is inserted");
    else println("3 is not inserted");
    // iterator from insertion points to found/inserted value:
    println(pair.first._M_node);
}

int main() {
    showSet();
    return 0;
}