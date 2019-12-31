#include <iostream>
using namespace std;

template<class T>
void println(T const &value) {
    cout << value << endl;
}

/* associative containers can be ORDERED (><) & UNORDERED (require hash-function)
 * common methods for associative containers:
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
    /* оператор [], или тот же emplace внутри него создаёт пару, в которой первый элемент это ключ,
     * а второй создаётся пустым, уже после чего в него присваивается значение.
     * Почему бы вместо конструктора по умолчанию оператору [] не вызвать конструктор от переданного в него значения?
     * Насколько мне известно, метод emplace у других контейнеров передаёт значение в конструктор класса элемента.
     * Почему у map значение ключа создаётся каким-то хитрым образом,
     * а "значение значения" создаётся обязательно конструктором по умолчанию, а потом присваиванием?
     * - потому что в оператор [] на момент вызова не передаётся больше никакого значения кроме значения ключа.
     * Присваивание происходит уже после возвращения оператором [] ссылки на созданное им значение,
     * после чего к этой ссылке применяется оператор присваивания = с передаваемым уже в нём "значением значения"
     */
    // special methods for map: operator[] and at() - in detail:
    auto it = phonebook.find("Margo");
    if (it != phonebook.end()) it->second = 22334455; // writing new value to existing element
    else phonebook.emplace("Margo", 22334455); // creating new object invoking its default constructor
    // lines above could be minimized to:
    phonebook["Margo"] = 11223344; // but here operations are the same - finding and assigning or insertion
    println(phonebook["Margo"]);
    /* some notes about operator[] in map:
     * - works only with non-const map
     * - requires presence of default constructor for type T
     * - works for O(log(n)) time - longer then linear time as for arrays
     * notes about method at() in map:
     * - generates runtime error if given key is absent - so it cannot create new element
     * - can work with const map and does not require presence of default constructor for type T
     * - works for O(log(n)) time - longer then linear time as for arrays
     */
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
//    phonebook["Homer"] = 123;
//    phonebook.at("Homer") = 123;
    // we see that there is NO operator[] and method at() for multimap
}

void showComparators() {
    // by default 'set' and 'map' have built-in default comparator 'less' that just invokes 'operator<'
    // but we can define our own comparator - for that we can reload operator<
    struct Person {
        Person(const char *name, const char *surname) : name(name), surname(surname) {}
        string name, surname;
        // we can define operator< here (with 1 argument of course)
        bool operator<(Person const &other) {
            return name < other.name || (name == other.name && surname < other.surname);
        }
    };
//    bool operator<(Person const &p1, Person const &p2) {
//        return p1.name < p2.name || (p1.name == p2.name && p1.surname < p2.surname);
//    }
    set<Person> persons1; // default comparator will be used here
//    persons1.emplace("a", "b");
//    persons1.emplace(Person("a", "b")); // insert also doesn't work

    // if we need another comparator - we can use a boolean method from another structure:
    struct PersonComparator {
        bool operator()(Person const &p1, Person const &p2) const {
            return p1.surname < p2.surname; // here we do not need comparison by names
        }
    };
    set<Person, PersonComparator> persons2; // our custom comparator will be used here
}

int main() {
    showSet();
    showMultiset();
    showMap();
    showMultimap();
    return 0;
}