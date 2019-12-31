#include <iostream>
using namespace std;

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
        cout << "11 is found" << endl;
}

void showUnorderedMap() {

}

int main() {
    showUnorderedSet();
    showUnorderedMap();
    return 0;
}