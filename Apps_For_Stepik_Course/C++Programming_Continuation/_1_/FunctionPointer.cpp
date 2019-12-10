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

// better way of doing the same things - but much more safer with handling types:

void sort_(int *p, int *q, bool (*compare)(int, int)) {
    for (int *m = q; m != p; --m)
        for (int *r = p; r + 1 < m; ++r)
            // if(*(r+1)<*r) - instead of this we'll use pointer to given comparator
            if (compare(*(r + 1), *r))
                std::swap(*r, *(r + 1));
}

bool lesser_(int a, int b) { return a < b; }
bool greater_(int a, int b) { return a > b; }
void sort_(int *p, int *q, bool ascending = true) {
    sort_(p, q, ascending ? &lesser_ : &greater_);
}

int main() {
    double a = 1.2;
    double b = 2.3;
//    sort(&a, &b);
    int i1 = 2;
    int i2 = 3;
    sort_(&i1, &i2);
    sort_(&i1, &i2, true);
    sort_(&i1, &i2, false);
    // for some reason output is: Process finished with exit code -1073741819 (0xC0000005)
    return 0;
}