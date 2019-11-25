#include "ComplexTemplates.hpp"

int main() {
    Array<long> la(9); // other 2 parameters will be automatically set to their defaults
    Array<double> da(9);
    Array<int, size_t, int const> triple(9);
    Array<Array<long>, size_t, Array<long> const> tripleComplex(9);
    typedef Array<long> Longs; // that simple - in fact 'typedef' acts as a plain synonym
    Array<Longs, size_t, Longs const> tripleTypedefs(9);
    /* previous line is the same as tripleComplex definition - but looks more simpler */
    Array<Longs, size_t, Longs const &> tripleTypedefRefs(9);
    /* returning value of third parameter is & - to avoid copying that may be expensive */
    return 0;
}