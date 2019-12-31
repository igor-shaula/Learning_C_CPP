#include <iostream>
using namespace std;

template<class T>
void println(T const &value) {
    cout << value << endl;
}

/* unlike older set & map, new standards unordered containers are based on hash-tables \
 * older set & map are ordered associative containers - these new are a bit different \
 * operations of addition, deletion and search take O(1) in average for unordered containers \
 * so these new unordered containers are faster in average - if number of buckets are sufficient \
 * all values in unordered_set cannot be changed - because they actually are keys as well \
 * common methods for unordered_set: equal_range(), reserve() and methods for hash-tables \
 */
#include <unordered_set>
void showUnorderedSet() {
    unordered_set<int> primes = {2, 3, 5, 7, 11};
    if (primes.find(11) != primes.end())
        println("11 is found");
    auto insResult = primes.insert(11); // this isn't done because duplicates are prohibited
    println(insResult.second);
}

void showUnorderedMultiset() {
    // std::unordered_multiset<T> is very similar to older multiset but is based on hash-table
    unordered_multiset<int> primes = {2, 3, 5, 7, 11};
    println(primes.size());
    auto insResult = primes.insert(11); // this time it's just iterator - not a pair like in set
    println(primes.size());
    println(*insResult); // we can dereference iterator - and receive a value under it
}

void showUnorderedMap() {

}

int main() {
    showUnorderedSet();
    showUnorderedMultiset();
    showUnorderedMap();
    return 0;
}