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
    /* std::set<T> stores ordered multitude as balanced binary search tree \
     * operations of addition, deletion and search work for O(log(n)) time \
     * values in set cannot be changed - because otherwise we'd have to re-balance binary tree \
     * in other words values here are keys so changing values leads to changing keys \
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
    // iterator from insertion points to found (if not inserted) or inserted (if new) value:
//    println(pair.first._M_node);
}

void showMultiset() {
    // std::multiset<T> always inserts any quantity of any values - so here duplicates are allowed
    multiset<int> fib = {0, 1, 1, 2, 3, 5, 8};
    // count()
    unsigned long count = fib.count(1);
    println(count);
    fib.insert(1); // iterator is returned - not a 'pair' like in 'set' - just 'iterator'
    println(fib.count(1));
    const multiset<int>::iterator &lowerBound = fib.lower_bound(1);
//    println(lowerBound);
    cout << *lowerBound << endl;
    const multiset<int>::iterator &upperBound = fib.upper_bound(1);
//    println(upperBound);
    cout << *upperBound << endl;
    const pair<multiset<int>::iterator, multiset<int>::iterator> &equalRange = fib.equal_range(1);
//    println(equalRange);
    cout << *equalRange.first << ' ' << *equalRange.second << endl;
    // it's possible to get range of different values - but how to do it ???
}

#include <map>
void showMap() {
    /* std::map stores ordered variety of key-value pairs which are ordered by key \
     * in other words map stores reflection from multitude of keys to multitude of values \
     * balanced binary search tree is used as realization of map - the same as for set \
     * as with std::set - map cannot keep duplicates - because they would have equal keys \
     * operations of addition, deletion and search work for O(log(n)) time - the same as in set \
     * typedef std::pair<const Key, T> value_type;
     * also has methods: lower_bound(), upper_bound() and equal_range() \
     * unlike std::set, std::map has accessors: operator[] & at() with access by value for both \
     * there is no possibility to change the key af any value - like in std::set
     */
    map<string, int> phonebook;
    phonebook.emplace("Margo", 2123456);
    phonebook.emplace("NotMargo", 2123456); // different key but equal value - it's OK for map
    phonebook.emplace("Lisa", 2123455);
    phonebook.emplace("Bart", 2123454);
    auto iterator = phonebook.find("Margo");
    if (iterator != phonebook.end())
        cout << "Margo found: " << iterator->second << endl;
}

void showMultimap() {
    // std::multimap<T> is like map but allows duplicates:
    multimap<string, int> phonebook;
    phonebook.emplace("Homer", 123456);
    phonebook.emplace("Homer", 123456); // duplicate value added intentionally
    phonebook.emplace("Homer", 1234567);
    unsigned long count = phonebook.count("Homer");
    println(count);
    // in all other meanings and usage multimap is like multiset
}

int main() {
    showSet();
    showMultiset();
    showMap();
    showMultimap();
    return 0;
}