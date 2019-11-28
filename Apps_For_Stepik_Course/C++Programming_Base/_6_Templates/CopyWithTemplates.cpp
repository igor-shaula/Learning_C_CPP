#include "CopyWithTemplates.hpp"
#include "iostream"

using namespace std;

template<typename U, typename T>
void copy_N(T *t, U const *u, size_t count) {
    for (size_t i = 0; i < count; ++i)
        *(t + i) = (U) *(u + i);
}

void testCopying() {
    int ints[] = {1, 2, 3, 4};
    double doubles[4] = {};
    copy_N(doubles, ints, 4); // теперь в массиве doubles содержатся элементы 1.0, 2.0, 3.0 и 4.0
    for (double d : doubles)
        cout << d << endl;
}

int main() {
    testCopying();
    return 0;
}