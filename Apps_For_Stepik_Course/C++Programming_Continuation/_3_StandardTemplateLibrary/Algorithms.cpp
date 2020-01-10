// functor = class, instances of which behave like functions - they have overloaded operator()
// predicate = functor which returns bool value

// all these algorithms are present in standard template library

#include <algorithm>
/* functors of standard library:
 * comparison predicates:
 - less, greater, less_equal, greater_equal, equal_to, not_equal_to\
 * arithmetic functors:
 - minus, plus, divides, modulus, multiplies\
 * logical_not, logical_and, logical_or
 * bit_and, bit_or, bit_xor
 * hash - used in unordered assotiative containers
 */

/* algorithms min/max - here we can use predicates
 * min - takes 2 elements and returns minimum of them
 * max - takes 2 elements and returns maximum of them
 * minmax - returns a pair where first value is min and second is max from given container
 - in new standard we can use min, max & minmax with initializer_list - but how exactly ???
 * min_element - returns iterator to min element
 * max_element - returns iterator to max element
 * minmax_element - returns a pair of iterators to min and max elements
 - last 6 algorithms take optional predicate which sets order in container
 */

/* non-modifying algorithms: (they don't change order in any sequence)
 - all_of , any_of , none_of - they all require predicate and a sequence via its two iterators
 - for_each (=for-loop) - also requires functor and a sequence via two iterators
 * - it applies this functor to each element of given sequence
 * - potentially an element can be changed by for_each - but only content passed by non-const reference
 * now algorithms that perform linear search:
 - find - takes a sequence and a value and returns iterator to found value or iterator to sequence end if not found
 - find_if - takes a sequence and predicate and returns iterator to first element where predicate is true
 - find_if_not - the same as previous but vice versa (where predicate is false)
 - find_first_of - takes 2 sequences and searches for start of inclusion of one of them into another\
 - adjacent_find - very complex to understand from words - a sample is needed here
 - count - returns number of found values equal to given one in a sequence
 - count_if - returns number of times when given predicate was true in given sequence
 - equal - returns true/false for two given sequences if they are equal or not
 - mismatch - returns a pair of iterators to first different element in each of two sequences
 * equal and mismatch take second sequence by only one iterator (unlike all others) -
 * so they assume that the second sequence is at least of the same length as first
 - is_permutation - takes 2 sequences and checks if 1st sequence is transposition of 2nd sequence
 - lexicographical_compare - compares 2 given sequences per elements - one by one, can accept predicate
 * searching for substring in given string:
 - search - finds place of inclusion of second sequence in first and returns this place
 - search_n - search for n substrings in a row inside greater given sequence
 - find_end (search_last) - returns last place of substring's inclusion in given string

 * algorithms for sorted sequences:
 - lower_bound , upper_bound , equal_range - they search for boundaries and take logarithmic time
 * these algorithms work with multitudes as with sorted sequences:
 - set_intersection , set_difference , set_union , set_symmetric_difference
 * the next algorithms check if certain element of sequence is present in other given sequence
 - binary_search - checks if element is inside given sequence and returns bool
 - includes - checks if one sequence is a subsequence of another given sequence
 */