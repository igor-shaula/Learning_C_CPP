#include <iostream>

using namespace std;

/* from source "algorithm":
 - fill , fill_n - for filling with concrete value
 - generate , generate_n - for filling with a value from given functor
 - random_shuffle , shuffle - old and new ways of tossing elements in container
 - copy , copy_n , copy_if , copy_backward - can copy a sequence via output iterator
 - move , move_backward - the same but using moving instead of copying
 - remove , remove_if , remove_copy , remove_copy_if - removing by value
 - replace , replace_if , replace_copy , replace_copy_if
 - reverse , reverse_copy - turning a sequence in place or via copying (beginning becomes an end)
 - rotate , rotate_copy - like shift in array to left or right ???
 - swap_ranges - rotates elements by their iterators
 - transform - applies operation over each element of given sequence (may be 2 sequences)
 - unique , unique_copy - lets to make every element unique by value - in place or via copying
 * from source "numeric":
 - accumulate - (non-modifying) - lets evaluate sum of elements
 - adjacent_difference - checks each pair of elements of 2 given sequences
 - inner_product - evaluates multitude of all elements in a sequence
 - partial_sum - lets evaluate partial sum or something else
 - iota - lets generate sequences of numbers for example
 */

#include <vector>
size_t size = 10;

void printVector(const string &s, vector<int> const &vi) {
    cout << s;
    for (size_t i = 0; i != size; ++i)
        cout << vi[i] << ' ';
    cout << endl;
}

#include <algorithm>
#include <numeric>
void showModifyingAlgorithms() {

    vector<int> a(size);
    // filling first vector with random values:
    generate(a.begin(), a.end(), []() { return rand() % size; });
    printVector("random with generate:\t\t", a);

    vector<int> b(size);
    // filling second vector with sequential values:
    iota(b.begin(), b.end(), 0); // starting from 0
    printVector("sequence with iota:\t\t", b);

    vector<int> c(size);
    // c[i] = a[i] * b[i];
    transform(a.begin(), a.end(), b.begin(), c.begin(), multiplies<>());
    printVector("multiplication with transform:\t", c);

    // c[i] *= 2;
    transform(c.begin(), c.end(), c.begin(), [](int x) { return x * 2; });
    printVector("second transformation:\t\t", c);

    // sum of c[i];
    int sum = accumulate(c.begin(), c.end(), 0);
    cout << "sum is: " << sum << endl;
    // every launch gives result 454 for unknown reason ...
}

#include <list>
void showRemovingElements() {
    vector<int> v = {2, 5, 1, 5, 8, 5, 2, 5, 8};
    cout << "initial size: " << v.size() << endl;
    remove(v.begin(), v.end(), 5); // it returns iterator to the end of modified sequence
    // in fact work here is done not with container but with its iterators viewed as a sequence
    cout << "size after remove: " << v.size() << endl; // 9
    printVector("after removing all 5: ", v);
    // for all containers except 'list' erase-remove idiom should be used for deletion of elements:
    v.erase(remove(v.begin(), v.end(), 5), v.end());
    // here result of inner 'remove' acts like begin iterator for a sequence of elements to delete
    cout << "size after erase-remove: " << v.size() << endl; // 7 - and one '5' is present there
    printVector("after erase-remove: ", v);

    // only for std::list<> remove() works as intended - for list erase-remove idiom is not needed
    list<int> l = {2, 5, 1, 5, 8, 5, 2, 5, 8};
    l.remove(5);
    cout << "size after removing from list: " << l.size() << endl;

    // removing of duplicates:
    vector<int> vd = {1, 22, 333, 4444, 55555};
    size = 5;
    vd.erase(unique(vd.begin(), vd.end()), vd.end());
    printVector("has to be unique: ", vd); // not unique in fact

    // removing from list:
    list<int> ld = {1, 22, 333, 4444, 55555};
    ld.unique();
    cout << ld.end().operator*() << endl; // checking last element
    list<int>::iterator it;
    // this fails on runtime fact...
//    auto sum = partial_sum(ld.begin(), ld.end(), it);
//    cout << *sum << endl;
}

#include <map>
void showRemovingFromAssotiativeContainers() {
    /* possible: erasing by iterator and erasing by key
     * if we want to 'remove_if' - it will fail because this algorithm changes order of elements
     * - but in assotiative containers there is no order - so we have a problem here
     */
    map<string, int> m; // here we'll try to remove element with value 0
    // wrong variant:
    for (auto it = m.begin(); it != m.end(); ++it) // problem will be here after erasing 'it'
        if (it->second == 0)
            m.erase(it); // after erasing this iterator it will be impossible to increment it
    // correct variant:
    for (auto it = m.begin(); it != m.end();) // no incrementing here
        if (it->second == 0)
            it = m.erase(it);
        else ++it; // safely erasing
    // alternative variant for old standard:
    for (map<string, int>::iterator it = m.begin(); it != m.end();) // no increment here
        if (it->second == 0)
            m.erase(it++); // postfix form of incrementing is crucial here - because old value is needed
        else ++it;
}

int main() {
    showModifyingAlgorithms();
    showRemovingElements();
    showRemovingFromAssotiativeContainers();
    return 0;
}