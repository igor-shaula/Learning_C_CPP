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
#include <algorithm>
#include <numeric>
void showModifyingAlgorithms() {
    size_t size = 10;

    vector<int> a(size);
    // filling first vector with random values:
    generate(a.begin(), a.end(), []() { return rand() % 10; }); // cannot use 'size' in lambda
    cout << "random with generate:\t\t";
    for (size_t i = 0; i != size; ++i)
        cout << a[i] << ' ';
    cout << endl;

    vector<int> b(size);
    // filling second vector with sequential values:
    iota(b.begin(), b.end(), 0); // starting from 0
    cout << "sequence with iota:\t\t";
    for (size_t i = 0; i != size; ++i)
        cout << b[i] << ' ';
    cout << endl;

    vector<int> c(size);
    // c[i] = a[i] * b[i];
    transform(a.begin(), a.end(), b.begin(), c.begin(), multiplies<>());
    cout << "multiplication with transform:\t";
    for (size_t i = 0; i != size; ++i)
        cout << c[i] << ' ';
    cout << endl;

    // c[i] *= 2;
    transform(c.begin(), c.end(), c.begin(), [](int x) { return x * 2; });
    cout << "second transformation:\t\t";
    for (size_t i = 0; i != size; ++i)
        cout << c[i] << ' ';
    cout << endl;

    // sum of c[i];
    int sum = accumulate(c.begin(), c.end(), 0);
    cout << "sum is: " << sum << endl;
    // every launch gives result 454 for unknown reason ...
}

int main() {
    showModifyingAlgorithms();
    return 0;
}