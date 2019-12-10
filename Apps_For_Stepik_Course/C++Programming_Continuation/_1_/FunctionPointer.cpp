#include <iostream>
using namespace std;

void qsort(void *base, size_t howMany, size_t size,
           int (*comparator)(void const *, void const *)); // 'comparator' is function pointer

int compareDoubles(void const *a, void const *b) {
    double da = *static_cast<double const *>(a);
    double db = *static_cast<double const *>(b);
    if (da < db) return -1;
    if (da > db) return +1;
    return 0;
}

void sort(double *p, double *q) {
    qsort(p, q - p, sizeof(double), &compareDoubles); // the last is the function's address
}

int main() {
    double a = 1.2;
    double b = 2.3;
    sort(&a, &b);
    return 0;
}