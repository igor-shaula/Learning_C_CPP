// functor = class, instances of which behave like functions - they have overloaded operator()
// predicate = functor which returns bool value

// all these algorithms are present in standard template library

#include <algorithm>
/* functors of standard library:
 * comparison predicates:
 - less
 - greater
 - less_equal
 - greater_equal
 - equal_to
 - not_equal_to
 * arithmetic functors:
 - minus
 - plus
 - divides
 - modulus
 - multiplies
 * logical_not
 * logical_and
 * logical_or
 * bit_and
 * bit_or
 * bit_xor
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